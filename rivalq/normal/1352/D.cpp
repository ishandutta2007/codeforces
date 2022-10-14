#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
struct node{
    int val;
    node* left;
    node* right; 
};
node* create(int val){
    node* temp=new node();
    temp->val=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
template<typename node>
struct my_deque{
     node* root=NULL;
     int sz=0;
     int size(){
        return sz;
     } 
     bool empty(){
        return sz==0;
     }
     //root itself will be front
     // root->right will be back
     void push_back(int val){
         if(root==NULL){
            root=create(val);
            root->left=root;
            root->right=root;
            sz++;
            return;
         }
         node* temp=create(val);
         temp->left=root;
         root->right->left=temp;
         temp->right=root->right;
         root->right=temp;
         sz++;
         return; 
     }
     void push_front(int val){
         if(root==NULL){
            root=create(val);
            root->left=root;
            root->right=root;
            sz++;
            return;
         }
         node* temp=create(val);
         root->right->left=temp;
         temp->right=root->right;
         root->right=temp;
         temp->left=root;
         root=temp;
         sz++;
         return;
     }
     void pop_back(){
         node* temp=root->right;
         root->right->right->left=root;
         root->right=root->right->right;
         delete(temp);
         sz--;
         return; 
     }
     void pop_front(){
          node* temp=root;
          root->left->right=root->right;
          root->right->left=root->left;
          root=root->left;
          delete(temp);
          sz--;
          return;
     } 
     int front(){
         return root->val;
     }
     int back(){
         return root->right->val;
     }
};


int solve(){
 int n;cin>>n;
 my_deque<node>dq;
 rep3(n){
    int t;cin>>t;
    dq.push_back(t);
 }
 int moves=0;
 int a=0;
 int b=0;
 int f=0;
 int prev=0;
 while(1){
    if(dq.empty())break;
    if(f==0){
        int s=0;
        while(!dq.empty() && s<=prev){
            s+=dq.front();
            dq.pop_front();
        }
        if(s<=prev){
            cout<<moves+1<<" "<<a+s<<" "<<b<<endl;return 0;
        }
        a+=s;
        prev=s;
        moves++;
        f^=1;
    }
    else{
        int s=0;
        while(!dq.empty() && s<=prev){
            s+=dq.back();
            dq.pop_back();
        }
        if(s<=prev){
            cout<<moves+1<<" "<<a<<" "<<b+s<<endl;return 0;
        }
        b+=s;
        prev=s;
        moves++;
        f^=1;
    }
 }
 cout<<moves<<" "<<a<<" "<<b<<endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}