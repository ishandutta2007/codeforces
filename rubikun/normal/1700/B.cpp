#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

string add(string a,string b){
    if(si(a)<si(b)) swap(a,b);
    
    for(int i=0;i<si(b);i++){
        a[si(a)-1-i]+=int(b[si(b)-1-i]-'0');
        if(a[si(a)-1-i]>'9'&&si(a)-1-i){
            a[si(a)-1-i]-=10;
            a[si(a)-1-i-1]++;
        }
    }
    for(int i=si(a)-1;i>=1;i--){
        if(a[i]>'9'){
            a[i]-=10;
            a[i-1]++;
        }
    }
    string res;
    
    if(a[0]>'9'){
        a[0]-=10;
        res+='1';
    }
    res+=a;
    
    for(int i=si(res)-1;i>=0;i--){
        if(res[i]>'9'){
            res[i]-=10;
            res[i-1]++;
        }
    }
    
    return res;
}

string sub(string a,string b){
    if(si(a)<si(b)) return "";
    if(si(a)==si(b)&&a<=b) return "";
    
    for(int i=0;i<si(b);i++){
        if(a[si(a)-1-i]<b[si(b)-1-i]){
            a[si(a)-1-i-1]--;
            a[si(a)-1-i]+=10;
        }
        a[si(a)-1-i]-=int(b[si(b)-1-i]-'0');
    }
    
    for(int i=si(a)-1;i>=0;i--){
        if(a[i]<'0'){
            a[i-1]--;
            a[i]+=10;
        }
    }
    int i=0;
    while(a[i]=='0') i++;
    
    return a.substr(i);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        if(S[0]=='9'){
            string T;
            for(int i=0;i<N+1;i++) T+='1';
            string res=sub(T,S);
            cout<<res<<"\n";
        }else{
            string T;
            for(int i=0;i<N;i++) T+='9';
            string res=sub(T,S);
            cout<<res<<"\n";
        }
    }
}