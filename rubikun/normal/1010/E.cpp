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
const int mod=1000000007,MAX=300005,INF=1<<30;

struct query{
    int z;
    int x;
    int y;
    int id;
};

void update(pair<int,int> &a,int b){
    chmin(a.fi,b);
    chmax(a.se,b);
}

int f(pair<int,int> a,int b){
    if(b<a.fi) return -1;
    if(a.se<b) return 1;
    return 0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int X,Y,Z;cin>>X>>Y>>Z;
    int N,M,Q;cin>>N>>M>>Q;
    pair<int,int> lx,ly,lz;
    lx=ly=lz=mp(INF,-INF);
    
    for(int i=0;i<N;i++){
        int x,y,z;cin>>x>>y>>z;
        update(lx,x);
        update(ly,y);
        update(lz,z);
    }
    
    vector<vector<query>> SS(8,vector<query>());
    
    // zxy
    
    for(int i=0;i<M;i++){
        int x,y,z;cin>>x>>y>>z;
        int fx=f(lx,x);
        int fy=f(ly,y);
        int fz=f(lz,z);
        
        if(fz==0){
            if(fx==0){
                if(fy==0){
                    cout<<"INCORRECT"<<endl;
                    return 0;
                }else if(fy==1){
                    SS[0].push_back({0,0,y});
                }else{
                    SS[1].push_back({0,0,-y});
                }
            }else if(fx==1){
                if(fy==0){
                    SS[0].push_back({0,x,0});
                }else if(fy==1){
                    SS[0].push_back({0,x,y});
                }else{
                    SS[1].push_back({0,x,-y});
                }
            }else{
                if(fy==0){
                    SS[2].push_back({0,-x,0});
                }else if(fy==1){
                    SS[2].push_back({0,-x,y});
                }else{
                    SS[3].push_back({0,-x,-y});
                }
            }
        }else if(fz==1){
            if(fx==0){
                if(fy==0){
                    SS[0].push_back({z,0,0});
                }else if(fy==1){
                    SS[0].push_back({z,0,y});
                }else{
                    SS[1].push_back({z,0,-y});
                }
            }else if(fx==1){
                if(fy==0){
                    SS[0].push_back({z,x,0});
                }else if(fy==1){
                    SS[0].push_back({z,x,y});
                }else{
                    SS[1].push_back({z,x,-y});
                }
            }else{
                if(fy==0){
                    SS[2].push_back({z,-x,0});
                }else if(fy==1){
                    SS[2].push_back({z,-x,y});
                }else{
                    SS[3].push_back({z,-x,-y});
                }
            }
        }else{
            if(fx==0){
                if(fy==0){
                    SS[4].push_back({-z,0,0});
                }else if(fy==1){
                    SS[4].push_back({-z,0,y});
                }else{
                    SS[5].push_back({-z,0,-y});
                }
            }else if(fx==1){
                if(fy==0){
                    SS[4].push_back({-z,x,0});
                }else if(fy==1){
                    SS[4].push_back({-z,x,y});
                }else{
                    SS[5].push_back({-z,x,-y});
                }
            }else{
                if(fy==0){
                    SS[6].push_back({-z,-x,0});
                }else if(fy==1){
                    SS[6].push_back({-z,-x,y});
                }else{
                    SS[7].push_back({-z,-x,-y});
                }
            }
        }
    }
    
    cout<<"CORRECT"<<endl;
    
    vector<query> T(Q);
    
    vector<int> ans(Q);
    
    for(int i=0;i<Q;i++){
        cin>>T[i].x>>T[i].y>>T[i].z;
        T[i].id=i;
        
        int fx=f(lx,T[i].x);
        int fy=f(ly,T[i].y);
        int fz=f(lz,T[i].z);
        
        if(fx==0&&fy==0&&fz==0) ans[i]=1;
    }
    
    for(int q=0;q<8;q++){
        auto S=SS[q];
        sort(all(S),[](auto a,auto b){
            if(a.z==b.z) return mp(a.x,a.y)<mp(b.x,b.y);
            return a.z<b.z;
        });
        sort(all(T),[](auto a,auto b){
            if(a.z==b.z) return mp(a.x,a.y)<mp(b.x,b.y);
            return a.z<b.z;
        });
        
        set<pair<int,int>> SE;
        
        SE.insert(mp(-INF,INF));
        SE.insert(mp(INF,-INF));
        
        int i=0,j=0;
        
        while(1){
            if(j==si(T)) break;
            
            if(i<si(S)&&S[i].z<=T[j].z){
                auto it=SE.upper_bound(mp(S[i].x,S[i].y));
                it--;
                if(S[i].y<(*it).se){
                    it++;
                    while(S[i].y<=(*it).se){
                        it=SE.erase(it);
                    }
                    SE.insert(mp(S[i].x,S[i].y));
                }
                
                i++;
            }else{
                auto it=SE.lower_bound(mp(T[j].x,INF));
                it--;
                if(T[j].y>=(*it).se) ans[T[j].id]=-1;
                
                j++;
            }
        }
        
        
        for(int i=0;i<Q;i++) T[i].y=-T[i].y;
        if(q&1) for(int i=0;i<Q;i++) T[i].x=-T[i].x;
        if(q%4==3) for(int i=0;i<Q;i++) T[i].z=-T[i].z;
    }
    
    sort(all(T),[](auto a,auto b){
        return a.id<b.id;
    });
    
    for(int i=0;i<Q;i++){
        if(ans[i]==1) cout<<"OPEN\n";
        if(ans[i]==0) cout<<"UNKNOWN\n";
        if(ans[i]==-1) cout<<"CLOSED\n";
    }
}