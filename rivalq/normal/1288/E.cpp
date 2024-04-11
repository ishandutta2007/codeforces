#include<bits/stdc++.h>


namespace WBST{



template<typename T, class Compare = std::less<int>>
class set{

	Compare comp;

	class node{	

	   public:	
		T val;
		size_t size;
		node *l;
		node *r;
		node(T val):val(val),l(nullptr),r(nullptr),size(1){}
		//friend class set;
	};
	node* root;

	size_t size(node* root){
		return root?root->size:0;
	}
	void upd_size(node* root){
		root->size = 1 + size(root->l) + size(root->r);
	}

	node* insert(node* root,T x){
		if(!root){
			return new node(x);
		}else{
			if(x == root->val){
				return root;
			}else if(comp(x,root->val)){
				root->l = insert(root->l,x);
			}else{
				root->r = insert(root->r,x);
			}
			upd_size(root);
			return root;
		}
	}	
	node* sucessor(node* root){
		root = root->r;
		while(root->l)root = root->l;
		return root;
	}

	node* erase(node* root, T x){
		if(!root){
			return root;
		}
		if(root->val == x){
			if((!root->l) and (!root->r)){
				delete(root);
				return nullptr;
			}else if(root->l and root->r){
				node* succ = sucessor(root);
				root->val = succ->val;
				root->r = erase(root->r,succ->val);
			}else if(root->l){
				root = root->l;
			}else{
				root = root->r;
			}
		}else if(comp(x,root->val)){
			root->l = erase(root->l,x);
		}else{
			root->r = erase(root->r,x);
		}
		upd_size(root);
		return root;
	}
	void inorder(node* root, std::vector<node*>& nodes){
		if(!root)return;
		inorder(root->l,nodes);
		nodes.push_back(root);
		inorder(root->r,nodes);
	}
	void build(int l,int r,node*& root,std::vector<node*>& nodes){
		if(l > r){
			return void(root = nullptr);
		}
		int mid = (l + r)/2;
		root = nodes[mid];
		build(l,mid - 1,root->l,nodes);
		build(mid + 1,r,root->r,nodes);
		upd_size(root);
	}


	node* rebalance(node* root, T x){
		if(!root or root->val == x)return root;
		else {
			size_t right = size(root->r);
			size_t left = size(root->l);
			size_t cur = size(root);
			if(10*std::max(right,left) > 9*cur){
				// rebuild tree
				std::vector<node*> nodes;
				inorder(root,nodes);
				int l = 0, r = nodes.size();r--;
				build(l,r,root,nodes);

			}else{
				if(comp(x,root->val)){
					root->l = rebalance(root->l,x);
				}else{
					root->r = rebalance(root->r,x);
				}
			}
			upd_size(root);
			return root;
		}
	}

	bool find(node* root, T x){
		if(!root)return false;

		if(root->val == x)return true;

		if(comp(x,root->val))return find(root->l,x);

		return find(root->r,x);
	}
	int32_t maxdepth(node* root){
		if(!root)return 0;
		return 1 + std::max(maxdepth(root->l),maxdepth(root->r));
	}
	void print(node* root,std::vector<int>&v){
		if(!root)return;
		print(root->l,v); 
		v.push_back(root->val);
		print(root->r,v);
	}


	int32_t order_of_key(node* root, T x){
		if(!root)return 0;
		if(comp(x,root->val)){
			return order_of_key(root->l,x);
		}else{
			return size(root->l) + order_of_key(root->r,x) + (comp(root->val,x));
		}
	}

	T find_by_order(node* root, int32_t order){
		if(order == size(root->l)){
			return root->val;
		}else if(order < size(root->l)){
			return find_by_order(root->l,order);
		}else{
			return find_by_order(root->r, order - size(root->l) - 1);
		}
	}


public:

	set(){
		root = nullptr;
	}
	size_t size(){
		return size(root);
	}
	void insert(T x){
		if(!root){
			root = new node(x);
		}else{
			insert(root,x);
			root = rebalance(root,x);
		}
	}
	bool find(T x){
		return find(root,x);
	}

	int32_t maxdepth(){
		return maxdepth(root);
	}

	void erase(T x){
		root = erase(root,x);
		//root = rebalance(root,x);
	}
	void print(std::vector<int>&v){
		print(root,v);
	}

	int32_t order_of_key(T x){
		return order_of_key(root,x);
	}

	T find_by_order(int32_t order){
		assert(root);
		if(order >= size(root)){
			order = size(root) - 1;
		}
		return find_by_order(root,order);
	}

};



}
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 


 

int main(){
		
		ios_base::sync_with_stdio(0);
		cin.tie(nullptr);

		int m,n; cin >> m >> n;

		vector<int> minimums(m + 1), maximums(m + 1);

		WBST::set<int> st;
		
		map<int,int> keys;

		for(int i = 1; i <= m; i++){
			keys[i] = i;
			st.insert(i);
			minimums[i] = i;
			maximums[i] = i;
		}
		int ptr = 0;


		auto debug = [&](){
			vector<int> v;
			st.print(v);
			for(auto i:v)cout << i << " ";
				cout << endl;
		};
		for(int i = 1; i <= n; i++){
			int p; cin >> p;
			minimums[p] = 1;
			//debug();
			int order = st.order_of_key(keys[p]) + 1;
			maximums[p] = max(maximums[p],order);
			st.erase(keys[p]);
			keys[p] = ptr--;
			st.insert(keys[p]);
		}



		for(int i = 1; i <= m; i++){
			int order = st.order_of_key(keys[i]) + 1;
			maximums[i] = max(maximums[i],order);
			cout << minimums[i] << " " << maximums[i] << "\n";
		}

		return 0;


}