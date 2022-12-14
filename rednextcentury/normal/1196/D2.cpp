#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define pii pair<int,int>
#define prec(n) fixed<<setprecision(n)
#define MOD 1000000007
#define eps 1e-8
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<","<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<" ";out<<*it;}out<<"";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");
 
int q,n,k,dp[200000];//dp[i] is ans for length i from start
string s;
 
int whatis(char c){
    if(c=='R')return 0;
    if(c=='G')return 1;
    return 2;
}
 
int f(int start){// r g b?
 
    dp[0]=whatis(s[0])!=(start)%3;
    for(int i=1;i<n;i++){
        if(whatis(s[i])!=(i+start)%3)dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-1];
    }
 
    int ansmin=dp[k-1];
    for(int i=k;i<n;i++){
        ansmin=min(ansmin,dp[i]-dp[i-k]);
    }
 
    return ansmin;
 
}
 
signed main(){
    FASTER;
 
    cin>>q;
 
    while(q--){
        cin>>n>>k>>s;
        cout<<min({f(0),f(1),f(2)})<<"\n";
    }
}