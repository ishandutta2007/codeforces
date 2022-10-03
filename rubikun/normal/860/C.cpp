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
const int mod=1000000007,MAX=3005,INF=1<<29;

void f(string A,int B){
    cout<<"move "<<A<<" "<<B<<"\n";
}

void f(int A,int B){
    cout<<"move "<<A<<" "<<B<<"\n";
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<string> AA,BB,A,B;
    deque<pair<string,bool>> chanA,chanB;
    queue<int> toA,toB;
    for(int i=0;i<N;i++){
        string S;cin>>S;
        int t;cin>>t;
        if(t) AA.push_back(S);
        else BB.push_back(S);
    }
    
    vector<int> used(N+1),usedused(1000000);
    int ngA=0,ngB=0;
    
    int M=si(AA);
    for(int i=0;i<si(AA);i++){
        bool ok=true;
        if(AA[i][0]=='0') ok=false;
        for(char c:AA[i]) if(!('0'<=c&&c<='9')) ok=false;
        if(ok){
            if(stoi(AA[i])>M){
                ok=false;
                if(stoi(AA[i])<=N){
                    ngA++;
                    chanA.push_front(mp(AA[i],1));
                    usedused[stoi(AA[i])]=true;
                }else{
                    chanA.push_back(mp(AA[i],0));
                }
            }else{
                used[stoi(AA[i])]=true;
            }
        }else{
            chanA.push_back(mp(AA[i],0));
        }
        if(!ok) A.push_back(AA[i]);
    }
    
    for(int i=0;i<si(BB);i++){
        bool ok=true;
        if(BB[i][0]=='0') ok=false;
        for(char c:BB[i]) if(!('0'<=c&&c<='9')) ok=false;
        if(ok){
            if(stoi(BB[i])>N||stoi(BB[i])<=M){
                ok=false;
                if(stoi(BB[i])<=M){
                    ngB++;
                    chanB.push_front(mp(BB[i],1));
                    usedused[stoi(BB[i])]=true;
                }else{
                    chanB.push_back(mp(BB[i],0));
                }
            }else{
                used[stoi(BB[i])]=true;
            }
        }else{
            chanB.push_back(mp(BB[i],0));
        }
        if(!ok) B.push_back(BB[i]);
    }
    
    if(si(A)==0&&si(B)==0){
        cout<<0<<endl;
        return 0;
    }
    
    if(ngA==si(A)&&ngB==si(B)&&ngA==ngB){
        cout<<ngA+ngB+1<<"\n";
        queue<int> RA,RB;
        for(int i=1;i<=N;i++){
            if(!used[i]&&i<=M) RA.push(i);
            if(!used[i]&&i>M) RB.push(i);
        }
        
        f(RA.front(),999999);
        while(!RA.empty()){
            f(RB.front(),RA.front());
            RA.pop();
            if(RA.empty()){
                f(999999,RB.front());
                RB.pop();
                break;
            }else{
                f(RA.front(),RB.front());
                RB.pop();
            }
        }
        
        return 0;
    }
    
    for(int i=1;i<=N;i++) if(used[i]) usedused[i]=true;
    
    for(int i=1;i<=M;i++) if(!usedused[i]) toA.push(i);
    for(int i=M+1;i<=N;i++) if(!usedused[i]) toB.push(i);
    
    cout<<si(A)+si(B)<<"\n";
    
    //cout<<si(chanA)<<" "<<si(chanB)<<endl;
    
    while(!chanA.empty()||!chanB.empty()){
        if(!chanA.empty()){
            if(chanA.front().se){
                if(!toA.empty()){
                    f(chanA.front().fi,toA.front());
                    toB.push(stoi(chanA.front().fi));
                    chanA.pop_front();
                    toA.pop();
                    continue;
                }
            }
        }
        if(!chanB.empty()){
            if(chanB.front().se){
                if(!toB.empty()){
                    f(chanB.front().fi,toB.front());
                    toA.push(stoi(chanB.front().fi));
                    chanB.pop_front();
                    toB.pop();
                    continue;
                }
            }
        }
        if(!chanA.empty()){
            if(!toA.empty()){
                f(chanA.front().fi,toA.front());
                chanA.pop_front();
                toA.pop();
                continue;
            }
        }
        if(!chanB.empty()){
            if(!toB.empty()){
                f(chanB.front().fi,toB.front());
                chanB.pop_front();
                toB.pop();
                continue;
            }
        }
        
        assert(true);
    }
}