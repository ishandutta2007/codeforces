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
			parent->recal();
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
			parent->recal();
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
		
		void special_insert(int val, int myidx) {
			int left_len;
			if(left == NULL) {
				left_len = 0;
			} else {
				left_len = left->len;
			}
			if(val-1 <= myidx+left_len+data) {
				if(left == NULL) {
					left = new AVLnode(val-myidx-left_len, this);
				} else {
					left->special_insert(val, myidx);
				}
			} else {
				if(right == NULL) {
					right = new AVLnode(val-myidx-left_len-1, this);
				} else {
					right->special_insert(val, myidx+left_len+1);
				}
			}
			len++;
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
		
		void destroy() {
			if(left != NULL) {
				left->destroy();
			}
			if(right != NULL) {
				right->destroy();
			}
			delete(this);
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
		
		void special_insert(int val) {
			if(root->left == NULL) {
				root->left = new AVLnode(val, root);
			} else {
				root->left->special_insert(val, 0);
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
		
		int len() {
			if(root->left == NULL) {
				return 0;
			} else {
				return root->left->len;
			}
		}
		
		void destroy() {
			if(root->left != NULL) {
				return root->left->destroy();
			}
		}
		
		void print() {
			if(root->left == NULL) {
				printf("Empty Tree\n");
			} else {
				root->left->print();
				printf("\n\n");
			}
		}
};

int NUM = 200000;
vector<long long> fact;

int pow_mod(int a, int k, int mod) {
	if(k == 0) {
		return 1;
	}
	int sub = pow_mod(a, k/2, mod);
	if(k%2 == 0) {
		return ((long long)sub*sub)%mod;
	} else {
		return (((long long)sub*sub)%mod*a)%mod;
	}
}

//p must be prime
int inv_mod(int a, int p) {
	return pow_mod(a, p-2, p);
}

int comb_mod(int n, int r, int mod) {
	long long div = (fact[r]*fact[n-r])%mod;
	return ((long long)fact[n]*inv_mod(div, mod))%mod;
}

int cmp_int(int a, int b) {
	if(a > b) {
		return 1;
	} else if(a < b) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int h, i, j, l;
	int t, n, m, k;
	int x;
	int start, end, mid;
	long long mod = 998244353;
	/*srand(time(NULL));
	AVLTree tree(NULL);
	for(i=1; i<=20; i++) {
		tree.special_insert(rand()%100);
		tree.print();
	}*/
	fact.push_back(1);
	for(i=1; i<=2*NUM; i++) {
		fact.push_back((fact[i-1]*i)%mod);
	}
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &m);
		int y[m];
		for(i=0; i<m; i++) {
			scanf("%d %d", &x, &y[i]);
		}
		AVLTree tree(NULL);
		for(i=0; i<m; i++) {
			/*start = -1;
			end = tree.len();
			while(start < end-1) {
				mid = (start+end)/2;
				int midval = tree.index(mid);
				if(midval+mid < y[i]-1) {
					start = mid;
				} else {
					end = mid;
				}
			}*/
			tree.special_insert(y[i]);
			/*for(j=0; j<tree.len(); j++) {
				printf("%d ", tree.index(j));
			}
			printf("\n");*/
		}
		int lt = 0;
		for(i=0; i<tree.len(); i++) {
			if(i == tree.len()-1 || tree.index(i)+i != tree.index(i+1)+i+1) {
				lt++;
			}
		}
		int lte = n-lt-1;
		printf("%d\n", comb_mod(n+lte, lte, mod));
		tree.destroy();
	}
}