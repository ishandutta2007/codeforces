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
const int mod=998244353,MAX=200005,INF=1<<30;

bool ask(vector<int> A,vector<int> B){
    cout<<"? ";
    int sz=si(A)+si(B);
    cout<<sz;
    for(int a:A) cout<<" "<<a;
    for(int a:B) cout<<" "<<a;
    cout<<endl;
    string res;cin>>res;
    if(res=="YES") return true;
    else return false;
}

bool ask(int x){
    cout<<"? 1 "<<x<<endl;
    string res;cin>>res;
    if(res=="YES") return true;
    else return false;
}

int main(){
    
    int N;cin>>N;
    vector<int> alive;
    for(int i=1;i<=N;i++) alive.push_back(i);
    
    while(si(alive)>=4){
        vector<vector<int>> S(4);
        for(int i=0;i<si(alive);i++) S[i%4].push_back(alive[i]);
        
        vector<int> A=S[0];
        vector<int> B=S[1];
        vector<int> C=S[2];
        vector<int> D=S[3];
        
        bool f=ask(A,B);
        bool g=ask(A,C);
        
        alive.clear();
        
        if(f){
            if(g){
                for(int a:A) alive.push_back(a);
                for(int a:B) alive.push_back(a);
                for(int a:C) alive.push_back(a);
            }else{
                for(int a:A) alive.push_back(a);
                for(int a:B) alive.push_back(a);
                for(int a:D) alive.push_back(a);
            }
        }else{
            if(g){
                for(int a:A) alive.push_back(a);
                for(int a:C) alive.push_back(a);
                for(int a:D) alive.push_back(a);
            }else{
                for(int a:B) alive.push_back(a);
                for(int a:C) alive.push_back(a);
                for(int a:D) alive.push_back(a);
            }
        }
    }
    
    if(si(alive)==1){
        cout<<"! "<<alive[0]<<endl;
        string res;cin>>res;
        if(res==":)") return 0;
    }
    
    if(si(alive)==2){
        cout<<"! "<<alive[0]<<endl;
        string res;cin>>res;
        if(res==":)") return 0;
        cout<<"! "<<alive[1]<<endl;
        cin>>res;
        if(res==":)") return 0;
    }
    
    int a=alive[0],b=alive[1],c=alive[2];
    bool f=ask(a);
    
    if(f){
        cout<<"! "<<a<<endl;
        string res;cin>>res;
        if(res==":)") return 0;
        
        bool g=ask(b);
        
        if(g){
            cout<<"! "<<b<<endl;
            string res;cin>>res;
            if(res==":)") return 0;
        }else{
            cout<<"! "<<c<<endl;
            string res;cin>>res;
            if(res==":)") return 0;
        }
    }
    
    f=ask(a);
    
    if(f){
        cout<<"! "<<a<<endl;
        string res;cin>>res;
        if(res==":)") return 0;
        
        bool g=ask(b);
        
        if(g){
            cout<<"! "<<b<<endl;
            string res;cin>>res;
            if(res==":)") return 0;
        }else{
            cout<<"! "<<c<<endl;
            string res;cin>>res;
            if(res==":)") return 0;
        }
    }
    
    cout<<"! "<<b<<endl;
    string res;cin>>res;
    if(res==":)") return 0;
    
    cout<<"! "<<c<<endl;
    cin>>res;
    if(res==":)") return 0;
}