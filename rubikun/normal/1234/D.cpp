#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

int bit[MAX+1][26],N;

//1-indexed

int sum(int i,int j){
    int s=0;
    while(i>0){
        s+=bit[i][j];
        i-=i&-i;
    }
    return s;
}

//st=sum(t)-sum(s-1)

void add(int i,int j,int x){
    while(i<=N){
        bit[i][j]+=x;
        i+=i&-i;
    }
}

int main(){
    
    string S;cin>>S;
    N=S.size();
    for(int i=0;i<S.size();i++){
        add(i+1,S[i]-'a',1);
    }
    int Q;cin>>Q;
    while(Q){
        int q;cin>>q;
        if(q==1){
            int a;char c;cin>>a>>c;
            add(a,S[a-1]-'a',-1);
            S[a-1]=c;
            add(a,S[a-1]-'a',1);
        }else{
            int l,r;cin>>l>>r;
            int ans=0;
            for(int i=0;i<26;i++){
                if(sum(r,i)-sum(l-1,i)) ans++;
            }
            cout<<ans<<endl;
        }
        Q--;
    }
}