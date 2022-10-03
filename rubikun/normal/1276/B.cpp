#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int par[MAX],size[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        size[root(a)]+=size[root(b)];
        par[root(b)]=root(a);
    }
}

bool check(int a,int b){
    return root(a)==root(b);
}


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M,A,B;cin>>N>>M>>A>>B;
        A--;B--;
        if(A>B) swap(A,B);
        vector<int> GA,GB;
        
        init(N);
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            if(a>b) swap(a,b);
            if(a!=A&&a!=B&&b!=A&&b!=B) unite(a,b);
            else{
                if(a==A&&b==B) continue;
                if(a==A) GA.push_back(b);
                if(a==B) GB.push_back(b);
                
                if(b==A) GA.push_back(a);
                if(b==B) GB.push_back(a);
            }
        }
        set<int> SE,SEA,SEB;
        for(int i=0;i<N;i++){
            if(root(i)!=A&&root(i)!=B) SE.insert(root(i));
        }
        for(int i=0;i<GA.size();i++) SEA.insert(root(GA[i]));
        for(int i=0;i<GB.size();i++) SEB.insert(root(GB[i]));
        
        ll left=0,right=0;
        
        for(auto it=SE.begin();it!=SE.end();it++){
            if(SEA.find(*it)!=SEA.end()){
                if(SEB.find(*it)==SEB.end()){
                    left+=size[*it];
                }
            }else{
                if(SEB.find(*it)!=SEB.end()){
                    right+=size[*it];
                }
            }
        }
        
        /*for(auto it=SE.begin();it!=SE.end();it++) cout<<*it<<" ";
        cout<<endl;
        
        for(auto it=SEA.begin();it!=SEA.end();it++) cout<<*it<<" ";
        cout<<endl;
        
        for(auto it=SEB.begin();it!=SEB.end();it++) cout<<*it<<" ";
        cout<<endl;*/
        
        //cout<<left<<" "<<right<<endl;
        
        cout<<left*right<<endl;
        
        //vector<int> a=search();
        /*for(int i=0;i<a.size();i++) cout<<a[i]+1<<" ";
        cout<<endl;*/
    }
}