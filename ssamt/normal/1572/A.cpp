#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

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
				return data;
			} else if(cmp(val, data) > 0) {
				if(right == NULL) {
					return -1;
				} else {
					return right->search(val, cmp);
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
				return data;
			} else if(cmp(val, data) > 0) {
				if(right == NULL) {
					return -1;
				} else {
					return right->search_larger(val, cmp);
				}
			} else {
				if(left == NULL) {
					return data;
				} else {
					int ret = left->search_larger(val, cmp);
					if(ret == -1) {
						return data;
					} else {
						return ret;
					}
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
				return -1;
			} else {
				return root->left->search_larger(val, cmp);
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

class AdjGraph {
	public:
		int n;
		std::vector< std::vector<int> > a;

		AdjGraph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                std::vector<int> e;
                a.push_back(e);
            }
		}

		void add(int i, int j) {
			a[i].push_back(j);
		}
		
		void print() {
			int i, j;
			printf("Graph\n");
			for(i=0; i<a.size(); i++) {
				printf("%d: ", i);
				for(j=0; j<a[i].size(); j++) {
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
		}
};

int main() {
	int h, i, j;
	int t, n;
	int in;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int k[n];
		AdjGraph graph(n);
		AVLTree tree(cmp_int);
		for(i=0; i<n; i++) {
			scanf("%d", &k[i]);
			for(j=0; j<k[i]; j++) {
				scanf("%d", &in);
				graph.add(in-1, i);
			}
			if(k[i] == 0) {
				tree.insert(i);
			}
		}
		//tree.print();
		//graph.print();
		int idx = 0;
		int count = n;
		int answer = 1;
		int found = 1;
		while(count > 0) {
			if(tree.root->left == NULL) {
				found = 0;
				break;
			}
			int next = tree.search_larger(idx);
			if(next == -1) {
				idx = tree.index(0);
				answer++;
			} else {
				count--;
				for(i=0; i<graph.a[next].size(); i++) {
					int adj = graph.a[next][i];
					k[adj]--;
					if(k[adj] == 0) {
						tree.insert(adj);
					}
				}
				//tree.print();
				tree.remove(next);
				idx = next;
			}
			//tree.print();
		}
		if(found) {
			printf("%d\n", answer);
		} else {
			printf("-1\n");
		}
	}
	/*AVLTree tree(cmp_int);
	vector<int> a{3,1,4,5,9,2,6};
	for(i=0; i<a.size(); i++) {
		tree.insert(a[i]);
		tree.print();
	}
	for(i=0; i<a.size(); i++) {
		tree.remove(a[i]);
		tree.print();
	}
	for(i=0; i<10; i++) {
		printf("%d:%d\n", i, tree.search_larger(i));
	}*/
	
}