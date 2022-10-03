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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int k;cin>>k;
        string sss,aaa,bbb;cin>>sss>>aaa>>bbb;
        int N=si(sss);
        vector<int> S(N),A(N),B(N);
        for(int i=0;i<N;i++) S[i]=sss[i]-'a';
        for(int i=0;i<N;i++) A[i]=aaa[i]-'a';
        for(int i=0;i<N;i++) B[i]=bbb[i]-'a';
        vector<int> to(k,-1),used(k,0);
        
        bool ok=true;
        int ii=-1;
        
        for(int i=0;i<N;i++){
            if(A[i]==B[i]){
                if(to[S[i]]==-1){
                    if(used[A[i]]==0){
                        to[S[i]]=A[i];
                        used[A[i]]=1;
                    }else ok=false;
                }else{
                    if(to[S[i]]!=A[i]) ok=false;
                }
            }else{
                ii=i;
                break;
            }
        }
        
        if(ii==-1||!ok){
            if(ok){
                cout<<"YES\n";
                for(int i=0;i<k;i++){
                    if(to[i]==-1){
                        for(int j=0;j<k;j++){
                            if(used[j]==0){
                                to[i]=j;
                                used[j]=1;
                                break;
                            }
                        }
                    }
                }
                for(int i=0;i<k;i++){
                    assert(0<=to[i]&&to[i]<k);
                    cout<<char('a'+to[i]);
                }
                cout<<"\n";
            }else{
                cout<<"NO\n";
            }
            
            continue;
        }
        
        vector<int> saveto=to,saveused=used;
        if(to[S[ii]]==-1){
            for(int j=A[ii];j<k;j++){
                if(used[j]==0){
                    to[S[ii]]=j;
                    used[j]=1;
                    break;
                }
            }
        }
        if(to[S[ii]]==-1){
            for(int j=0;j<k;j++){
                if(used[j]==0){
                    to[S[ii]]=j;
                    used[j]=1;
                    break;
                }
            }
        }
        
        for(int i=ii+1;i<N;i++){
            if(to[S[i]]==-1){
                for(int j=k-1;j>=0;j--){
                    if(used[j]==0){
                        to[S[i]]=j;
                        used[j]=1;
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<k;i++){
            if(to[i]==-1){
                for(int j=0;j<k;j++){
                    if(used[j]==0){
                        to[i]=j;
                        used[j]=1;
                        break;
                    }
                }
            }
        }
        
        vector<int> T(N);
        for(int i=0;i<N;i++){
            T[i]=to[S[i]];
        }
        
        if(A<=T&&T<=B){
            cout<<"YES\n";
            for(int i=0;i<k;i++){
                assert(0<=to[i]&&to[i]<k);
                cout<<char('a'+to[i]);
            }
            cout<<"\n";
            continue;
        }
        
        to=saveto;
        used=saveused;
        
        if(to[S[ii]]==-1){
            for(int j=B[ii];j>=0;j--){
                if(used[j]==0){
                    to[S[ii]]=j;
                    used[j]=1;
                    break;
                }
            }
        }
        if(to[S[ii]]==-1){
            for(int j=k-1;j>=0;j--){
                if(used[j]==0){
                    to[S[ii]]=j;
                    used[j]=1;
                    break;
                }
            }
        }
        
        for(int i=ii+1;i<N;i++){
            if(to[S[i]]==-1){
                for(int j=0;j<k;j++){
                    if(used[j]==0){
                        to[S[i]]=j;
                        used[j]=1;
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<k;i++){
            if(to[i]==-1){
                for(int j=0;j<k;j++){
                    if(used[j]==0){
                        to[i]=j;
                        used[j]=1;
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<N;i++){
            T[i]=to[S[i]];
        }
        
        if(A<=T&&T<=B){
            cout<<"YES\n";
            for(int i=0;i<k;i++){
                assert(0<=to[i]&&to[i]<k);
                cout<<char('a'+to[i]);
            }
            cout<<"\n";
            continue;
        }
        
        to=saveto;
        used=saveused;
        
        if(to[S[ii]]==-1){
            for(int j=B[ii]-1;j>=0;j--){
                if(used[j]==0){
                    to[S[ii]]=j;
                    used[j]=1;
                    break;
                }
            }
        }
        if(to[S[ii]]==-1){
            for(int j=k-1;j>=0;j--){
                if(used[j]==0){
                    to[S[ii]]=j;
                    used[j]=1;
                    break;
                }
            }
        }
        
        for(int i=ii+1;i<N;i++){
            if(to[S[i]]==-1){
                for(int j=0;j<k;j++){
                    if(used[j]==0){
                        to[S[i]]=j;
                        used[j]=1;
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<k;i++){
            if(to[i]==-1){
                for(int j=0;j<k;j++){
                    if(used[j]==0){
                        to[i]=j;
                        used[j]=1;
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<N;i++){
            T[i]=to[S[i]];
        }
        
        if(A<=T&&T<=B){
            cout<<"YES\n";
            for(int i=0;i<k;i++){
                assert(0<=to[i]&&to[i]<k);
                cout<<char('a'+to[i]);
            }
            cout<<"\n";
            continue;
        }else{
            cout<<"NO\n";
        }
        
    }
    
}