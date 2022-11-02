#include <bits/stdc++.h>

using namespace std;

class AVLnode {
	public:
		int data;
		int len;
		int height;
		AVLnode* left;
		AVLnode* right;
		AVLnode* parent;
		
		AVLnode(int data, AVLnode* parent) {
			this->data = data;
			len = 1;
			height = 1;
			left = NULL;
			right = NULL;
			this->parent = parent;
		}
		
		void recal() {
			len = 1;
			if(left != NULL) {
				len += left->len;
			}
			if(right != NULL) {
				len += right->len;
			}
			height = 0;
			if(left != NULL) {
				height = max(height, left->height);
			}
			if(right != NULL) {
				height = max(height, right->height);
			}
			height++;
		}
		
		void ll() {
			AVLnode* temp = left;
			if(parent != NULL) {
				if(parent->left == this) {
					parent->left = temp;
				} else {
					parent->right = temp;
				}
			}
			temp->parent = parent;
			left = temp->right;
			if(temp->right != NULL) {
				temp->right->parent = this;
			}
			temp->right = this;
			parent = temp;
			recal();
			temp->recal();
		}
		
		void rr() {
			AVLnode* temp = right;
			if(parent != NULL) {
				if(parent->left == this) {
					parent->left = temp;
				} else {
					parent->right = temp;
				}
			}
			temp->parent = parent;
			right = temp->left;
			if(temp->left != NULL) {
				temp->left->parent = this;
			}
			temp->left = this;
			parent = temp;
			recal();
			temp->recal();
		}
		
		int diff() {
			int leftl, rightl;
			if(left == NULL) {
				leftl = 0;
			} else {
				leftl = left->height;
			}
			if(right == NULL) {
				rightl = 0;
			} else {
				rightl = right->height;
			}
			return rightl-leftl;
		}
		
		void balance() {
			int factor = diff();
			if(factor > 1) {
				int factor2 = right->diff();
				if(factor2 < 0) {
					right->ll();
				}
				rr();
			} else if(factor < -1) {
				int factor2 = left->diff();
				if(factor2 > 0) {
					left->rr();
				}
				ll();
			}
		}
		
		void insert(int val, int (*cmp)(int, int)) {
			if(cmp(val, data) >= 0) {
				if(right == NULL) {
					right = new AVLnode(val, this);
				} else {
					right->insert(val, cmp);
				}
			} else {
				if(left == NULL) {
					left = new AVLnode(val, this);
				} else {
					left->insert(val, cmp);
				}
			}
			len++;
			recal();
			balance();
		}
		
		void insert_index(int val, int idx) {
			int left_len;
			if(left == NULL) {
				left_len = 0;
			} else {
				left_len = left->len;
			}
			if(idx <= left_len) {
				if(left == NULL) {
					left = new AVLnode(val, this);
				} else {
					left->insert_index(val, idx);
				}
			} else {
				if(right == NULL) {
					right = new AVLnode(val, this);
				} else {
					right->insert_index(val, idx-left_len-1);
				}
			}
			len++;
			recal();
			balance();
		}
		
		void remove(int val, int (*cmp)(int, int)) {
			if(cmp(val, data) == 0) {
				if(left == NULL) {
					if(parent->left == this) {
						parent->left = right;
					} else {
						parent->right = right;
					}
					if(right != NULL) {
						right->parent = parent;
					}
					delete(this);
					return;
				} else {
					if(right == NULL) {
						if(parent->left == this) {
							parent->left = left;
						} else {
							parent->right = left;
						}
						if(left != NULL) {
							left->parent = parent;
						}
						delete(this);
						return;
					} else {
						int replace = left->index(left->len-1);
						data = replace;
						left->remove(replace, cmp);
					}
				}
			} else if(cmp(val, data) > 0) {
				if(right != NULL) {
					right->remove(val, cmp);
				}
			} else {
				if(left != NULL) {
					left->remove(val, cmp);
				}
			}
			recal();
			balance();
		}
		
		int search(int val, int (*cmp)(int, int)) {
			if(cmp(val, data) == 0) {
				return 0;
			} else if(cmp(val, data) > 0) {
				if(right == NULL) {
					return -1;
				} else {
					return left->len+right->search(val, cmp);
				}
			} else {
				if(left == NULL) {
					return -1;
				} else {
					return left->search(val, cmp);
				}
			}
		}
		
		int search_larger(int val, int (*cmp)(int, int)) {
			if(cmp(val, data) == 0) {
				return 0;
			} else if(cmp(val, data) > 0) {
				int ret = 1;
				if(left != NULL) {
					ret += left->len;
				}
				if(right != NULL) {
					ret += right->search_larger(val, cmp);
				}
				return ret;
			} else {
				if(left == NULL) {
					return 0;
				} else {
					return left->search_larger(val, cmp);
				}
			}
		}
		
		int index(int idx) {
			int left_len;
			if(left == NULL) {
				left_len = 0;
			} else {
				left_len = left->len;
			}
			if(idx == left_len) {
				return data;
			} else if(idx > left_len) {
				if(right == NULL) {
					return -1;
				} else {
					return right->index(idx-left_len-1);
				}
			} else {
				if(left == NULL) {
					return -1;
				} else {
					return left->index(idx);
				}
			}
		}
		
		void print() {
			if(left != NULL) {
				left->print();
				printf("\n");
			}
			printf("%d %d %d %d", data, len, height, parent->data);
			if(right != NULL) {
				printf("\n");
				right->print();
			}
		}
};

class AVLTree {
	public:
		//root->left is the real pointer
		AVLnode* root;
		int (*cmp)(int, int);
		
		AVLTree(int (*cmp)(int, int)) {
			root = new AVLnode(0, NULL);
			this->cmp = cmp;
		}
		
		void insert(int val) {
			if(root->left == NULL) {
				root->left = new AVLnode(val, root);
			} else {
				root->left->insert(val, cmp);
			}
		}
		
		void insert_index(int val, int idx) {
			if(root->left == NULL) {
				root->left = new AVLnode(val, root);
			} else {
				root->left->insert_index(val, idx);
			}
		}
		
		void remove(int val) {
			if(root->left != NULL) {
				root->left->remove(val, cmp);
			}
		}
		
		int index(int idx) {
			if(root->left == NULL) {
				return -1;
			} else {
				return root->left->index(idx);
			}
		}
		
		int search(int val) {
			if(root->left == NULL) {
				return -1;
			} else {
				return root->left->search(val, cmp);
			}
		}
		
		int search_larger(int val) {
			if(root->left == NULL) {
				return 0;
			} else {
				return root->left->search_larger(val, cmp);
			}
		}
		
		int len() {
			if(root->left == NULL) {
				return 0;
			} else {
				return root->left->len;
			}
		}
		
		void print() {
			if(root->left == NULL) {
				printf("Empty Tree\n");
			} else {
				printf("Tree\n");
				root->left->print();
				printf("\n\n");
			}
		}
};

int cmp_int(int a, int b) {
	return a-b;
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		getchar();
		scanf("%d %d", &n, &m);
		char s[n][m+1];
		int a[n][m];
		for(i=0; i<n; i++) {
			scanf("%s", s[i]);
			for(j=0; j<m; j++) {
				a[i][j] = s[i][j]-'0';
			}
		}
		int answer = 0;
		for(int par=0; par<2; par++) {
			int first[n];
			for(i=0; i<n; i++) {
				for(j=(i+par)%2; j<m && !a[i][j]; j+=2);
				first[i] = j;
			}
			while(true) {
				vector<vector<int>> order;
				for(i=0; i<n; i++) {
					order.push_back({first[i], i});
				}
				sort(order.begin(), order.end());
				if(order[0][0] >= m) {
					break;
				}
				int change[n] = {};
				AVLTree tree(cmp_int);
				for(i=0; i<n; i++) {
					int ni = order[i][1];
					int nj = order[i][0];
					if(nj >= m) {
						break;
					}
					int idx = tree.search_larger(ni);
					int pass = 1;
					//printf("%d %d %d\n", ni, nj, idx);
					if(idx != 0) {
						int bef = tree.index(idx-1);
						if(abs(bef-ni) < abs(first[bef]-nj)) {
							pass = 0;
						}
					}
					if(idx != tree.len()) {
						int aft = tree.index(idx);
						if(abs(aft-ni) < abs(first[aft]-nj)) {
							pass = 0;
						}
					}
					if(pass) {
						tree.insert(ni);
						change[ni] = 1;
					}
				}
				for(i=0; i<n; i++) {
					if(change[i]) {
						for(j=first[i]+2; j<m && !a[i][j]; j+=2);
						first[i] = j;
					}
				}
				answer++;
			}
		}
		printf("%d\n", answer);
	}
}