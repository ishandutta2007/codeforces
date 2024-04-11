// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


template<typename T>
class binary_heap{
        
        vector<T> tree;
        function<T(const T&, const T&)> compare;


        void up_heapify(int id){
                while(id){
                        int parent_id = (id - 1)/2;
                        if(compare(tree[id],tree[parent_id])){
                                swap(tree[id],tree[parent_id]);
                                swap(id,parent_id);
                        }else{
                                break;
                        }
                }
        }


        void down_heapify(int id){
                int left_child = 2*id + 1;
                int right_child = 2*id + 2;
                swap(left_child,right_child);
                if(left_child < tree.size() and right_child < tree.size()){
                        if(compare(tree[right_child],tree[left_child])){
                                if(compare(tree[right_child],tree[id])){
                                        swap(tree[right_child],tree[id]);
                                        down_heapify(right_child);
                                }
                        }else{
                                if(compare(tree[left_child],tree[id])){
                                        swap(tree[left_child],tree[id]);
                                        down_heapify(left_child);
                                }
                        }
                }else if(left_child < tree.size()){
                        if(compare(tree[left_child],tree[id])){
                                        swap(tree[left_child],tree[id]);
                                        down_heapify(left_child);
                        }
                }else if(right_child < tree.size()){
                        if(compare(tree[right_child],tree[id])){
                                        swap(tree[right_child],tree[id]);
                                        down_heapify(right_child);
                        }
                }
        }

public:
        void push(T val){
                int id = tree.size();
                tree.push_back(val);
                up_heapify(id);
        }       

        void pop(){
                if(tree.size() == 1){
                        tree.clear();
                }else{
                        tree[0] = tree.back();
                        tree.pop_back();
                        down_heapify(0);
                }
        }

        T top(){
                return tree[0]; 
        }

        binary_heap(function<T(const T&, const T&)> compare):compare(compare){

        }


};


int solve(){
 		int n; cin >> n;
 		vector<pair<int,int>>vec;
 		for(int i = 0; i < n; i++){
 			int x,y; cin >> x >> y;
 			vec.push_back({x + y,x - y});
 		}
 		sort(vec.begin(),vec.end());
 		int ans = 0;
 		binary_heap<int> right([&](int x,int y){
                        return x < y;
                });
                binary_heap<int> left([&](int x,int y){
                        return x > y;
                });
 		int last = 0;
 		left.push(last);
 		right.push(last);
 		int left_shift = 0;
 		int right_shift = 0;
 		for(auto i:vec){
 			int x = i.x;
 			int y = i.y;
 			left_shift -= x - last;
 			right_shift += x - last;
 			last = x;
 			int min_right = right.top() + right_shift;
 			int max_left = left.top() + left_shift;
 			if(y >= max_left and y <= min_right){
 				left.push(y - left_shift);
 				right.push(y - right_shift);
 			}else if(y > min_right){
 				ans += (y - min_right);
 				right.push(y - right_shift);
 				right.push(y - right_shift);
 				left.push(right.top() + right_shift - left_shift);
 				right.pop();
 			}else{
 				ans += max_left - y;
 				left.push(y - left_shift);
 				left.push(y - left_shift);
 				right.push(left.top() + left_shift - right_shift);
 				left.pop();
 			}
 		}
 		ans /= 2;
 		cout << ans << endl;

 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}