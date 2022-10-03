#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<29;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int N,M;//cin>>N>>M;
        scanf("%d%d",&N,&M);
        vector<pair<int,int>> P(M);
        vector<int> usedv(3*N+1,0),usede(M+1,0);

        for(int i=0;i<M;i++){
            scanf("%d%d",&P[i].first,&P[i].second);
            //cin>>P[i].first>>P[i].second;
        }
        
        for(int i=0;i<M;i++){
            if(!usedv[P[i].first]&&!usedv[P[i].second]){
                usede[i+1]=1;
                usedv[P[i].first]=usedv[P[i].second]=1;
            }
        }
        
        int cnt=0;
        
        for(int i=1;i<=M;i++){
            if(usede[i]) cnt++;
        }
        
        if(cnt>=N){
            //cout<<"Matching"<<endl;
            printf("Matching\n");
            cnt=N;
            for(int i=1;i<=M;i++){
                if(usede[i]){
                    if(cnt!=N){
                        //cout<<" ";
                        printf(" ");
                    }
                    //cout<<i;
                    printf("%d",i);
                    cnt--;
                }
                if(cnt==0) break;
            }
            //cout<<endl;
            printf("\n");
        }else{
            cnt=N;
            //cout<<"IndSet"<<endl;
            printf("IndSet\n");
            for(int i=1;i<=3*N;i++){
                if(!usedv[i]){
                    if(cnt!=N){
                        //cout<<" ";
                        printf(" ");
                    }
                    //cout<<i;
                    printf("%d",i);
                    cnt--;
                }
                if(cnt==0) break;
            }
            //cout<<endl;
            printf("\n");
        }
    }
    
    
    
}