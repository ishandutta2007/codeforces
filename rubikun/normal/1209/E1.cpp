#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

struct point{
    int p;
    int x;
    int y;
};

bool compare(point a,point b){
    if(a.p==b.p) return a.x<b.x;
    return a.p>b.p;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int N,M;cin>>N>>M;
        if(N<=3){
            vector<int> A(N*M);
            for(int i=0;i<N*M;i++){
                cin>>A[i];
            }
            sort(all(A));
            reverse(all(A));
            int ans=0;
            for(int i=0;i<N;i++){
                ans+=A[i];
            }
            cout<<ans<<endl;
        }else{
            vector<point> A(N*M),B(N*M);
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    int x;cin>>x;
                    A[i*M+j]={x,i,j};
                    B[i*M+j]=A[i*M+j];
                }
            }
            
            sort(all(A),compare);
            
            set<int> a;
            for(int i=0;i<4;i++){
                a.insert(A[i].y);
            }
            if(a.size()!=2){
                int ans=0;
                for(int i=0;i<N;i++){
                    ans+=A[i].p;
                }
                cout<<ans<<endl;
            }else{
                int s,t,u=-1;
                auto it=a.begin();
                s=(*it);it++;
                t=(*it);
                for(int i=4;i<N*M;i++){
                    if(A[i].y!=s&&A[i].y!=t){
                        u=A[i].p;
                        break;
                    }
                }
                int ans=0;
                
                if(u==-1){
                    for(int bit=0;bit<(1<<8);bit++){
                        vector<int> on;
                        int sum=0;
                        for(int i=0;i<8;i++){
                            if(bit&(1<<i)) on.push_back(i);
                        }
                        if(on.size()!=4) continue;
                        if(on[1]<=3&&on[2]>=4){
                            if((on[1]-on[0]==2&&on[3]-on[2]!=2)||(on[1]-on[0]!=2&&on[3]-on[2]==2)) continue;
                            for(int j=0;j<4;j++){
                                if(on[j]<=3){
                                    sum+=B[on[j]*M+s].p;
                                }else{
                                    sum+=B[(on[j]-4)*M+t].p;
                                }
                                //if(bit==51) cout<<sum<<endl;
                            }
                            ans=max(ans,sum);
                            //cout<<bit<<" "<<sum<<endl;
                        }else{
                            for(int j=0;j<4;j++){
                                if(on[j]<=3){
                                    sum+=B[on[j]*M+s].p;
                                }else{
                                    sum+=B[(on[j]-4)*M+t].p;
                                }
                                //if(bit==51) cout<<sum<<endl;
                            }
                            ans=max(ans,sum);
                        }
                    }
                }else{
                    for(int bit=0;bit<(1<<8);bit++){
                        vector<int> on;
                        int sum=0;
                        for(int i=0;i<8;i++){
                            if(bit&(1<<i)) on.push_back(i);
                        }
                        if(on.size()==4){
                            if(on[1]<=3&&on[2]>=4){
                                if((on[1]-on[0]==2&&on[3]-on[2]!=2)||(on[1]-on[0]!=2&&on[3]-on[2]==2)) continue;
                                for(int j=0;j<4;j++){
                                    if(on[j]<=3){
                                        sum+=B[on[j]*M+s].p;
                                    }else{
                                        sum+=B[(on[j]-4)*M+t].p;
                                    }
                                }
                                ans=max(ans,sum);
                            }else{
                                for(int j=0;j<4;j++){
                                    if(on[j]<=3){
                                        sum+=B[on[j]*M+s].p;
                                    }else{
                                        sum+=B[(on[j]-4)*M+t].p;
                                    }
                                    //if(bit==51) cout<<sum<<endl;
                                }
                                ans=max(ans,sum);
                            }
                        }else if(on.size()==3){
                            for(int j=0;j<3;j++){
                                if(on[j]<=3){
                                    sum+=B[on[j]*M+s].p;
                                }else{
                                    sum+=B[(on[j]-4)*M+t].p;
                                }
                            }
                            sum+=u;
                            ans=max(ans,sum);
                        }
                    }
                }
                cout<<ans<<endl;
            }
        }
    }
}