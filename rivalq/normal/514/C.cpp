//https://codeforces.com/problemset/problem/514/C
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
   node* sons[3]={NULL};
   int cnt=0;
   bool end=false;
};
template<typename node>
struct trie{
   node* root=new node();
   node* create(){
       node* temp=new node();
       temp->sons[0]=NULL;
       temp->sons[1]=NULL;
       temp->sons[2]=NULL;
       temp->end=false;
       temp->cnt=0;
       return temp;
   } 
   void insert(string &p){
       node* temp=root;
       int n=p.length();
       for(int i=0;i<n;i++){
           temp->cnt++;
           int c=p[i]-97;
           if(temp->sons[c]==NULL){
               temp->sons[c]=create();
               temp=temp->sons[c];
           }
           else{
               temp=temp->sons[c];
           } 
       }
       temp->cnt++;
       temp->end=true;
   }
   void erase(string &p){
       node* temp=root;
       for(int i=0;i<p.length();i++){
           temp->cnt--;
           char c=p[i]-97;
           temp=temp->sons[c];
       }
       temp->cnt--;
   }
   bool dfs(int i,int n,string &p,int changes,node* temp){
      if(changes>1)return false; 
      if(i==n){
          //cout<<p<<" "<<changes<<endl;
          return changes==1 && temp->end;
      }
      node* t1=temp->sons[0];
      node* t2=temp->sons[1];
      node* t3=temp->sons[2];
      bool f1=false;
      if(t1)f1=dfs(i+1,n,p,changes+(p[i]!='a'),t1);
      if(f1)return true;
      if(t2)f1=dfs(i+1,n,p,changes+(p[i]!='b'),t2);
      if(f1)return true;
      if(t3)f1=dfs(i+1,n,p,changes+(p[i]!='c'),t3);
      if(f1)return true;
      return false;
   }
};
trie<node>tree;
int solve(){
  int n,m;cin>>n>>m;          
  rep3(n){
      string s;cin>>s;
      tree.insert(s);  
  }          
  rep3(m){
      string t;cin>>t;
      node* temp=tree.root;
      if(tree.dfs(0,t.length(),t,0,temp))cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
  }
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}