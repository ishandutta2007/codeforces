#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000005,INF=2000000003;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<int> personcnt(1<<9,0),mini1(1<<9,INF),mini2(1<<9,INF);
    for(int i=0;i<N;i++){
        int t;scanf("%d",&t);
        int sum=0;
        for(int j=0;j<t;j++){
            int a;scanf("%d",&a);
            a--;
            sum=sum|(1<<a);
        }
        for(int j=0;j<(1<<9);j++){
            if((sum|j)==j) personcnt[j]++;
        }
    }
    
    vector<int> cost(M),bit(M);
    
    for(int i=0;i<M;i++){
        int c,t;scanf("%d%d",&c,&t);
        cost[i]=c;
        int sum=0;
        for(int j=0;j<t;j++){
            int a;scanf("%d",&a);
            a--;
            sum=sum|(1<<a);
        }
        bit[i]=sum;
        if(c<=mini1[sum]){
            mini2[sum]=mini1[sum];
            mini1[sum]=c;
        }else mini2[sum]=min(mini2[sum],c);
    }
    
    int maxi=0,ans=INF,leftprice=INF,rightprice=INF,leftbit=0,rightbit=0;
    
    for(int i=0;i<(1<<9);i++){
        if(mini1[i]==INF) continue;
        for(int j=0;j<(1<<9);j++){
            if(i==j&&mini2[j]==INF) continue;
            if(mini1[j]==INF) continue;
            int uni=personcnt[(i|j)];
            if(maxi<uni){
                maxi=uni;
                if(i!=j){
                    ans=mini1[i]+mini1[j];
                    leftprice=mini1[i];
                    rightprice=mini1[j];
                    leftbit=i;
                    rightbit=j;
                }else{
                    ans=mini1[i]+mini2[i];
                    leftprice=mini1[i];
                    rightprice=mini2[i];
                    leftbit=i;
                    rightbit=j;
                }
            }else if(maxi==uni){
                if(i!=j&&ans>mini1[i]+mini1[j]){
                    ans=mini1[i]+mini1[j];
                    leftprice=mini1[i];
                    rightprice=mini1[j];
                    leftbit=i;
                    rightbit=j;
                }else if(i==j&&ans>mini1[i]+mini2[i]){
                    ans=mini1[i]+mini2[i];
                    leftprice=mini1[i];
                    rightprice=mini2[i];
                    leftbit=i;
                    rightbit=j;
                }
            }
        }
    }
    
    int a=-1,b=-1;
    
    for(int i=0;i<M;i++){
        if(a==-1){
            if(leftprice==cost[i]&&leftbit==bit[i]) a=i+1;
        }else{
            if(rightprice==cost[i]&&rightbit==bit[i]) b=i+1;
        }
    }
    
    for(int i=0;i<M;i++){
        if(a==-1){
            if(leftprice==cost[i]&&leftbit==bit[i]) a=i+1;
        }else{
            if(rightprice==cost[i]&&rightbit==bit[i]) b=i+1;
        }
    }
    
    if(b==-1){
        int mini=INF;
        for(int i=0;i<M;i++){
            if(i==a-1) continue;
            if(cost[i]<mini){
                mini=cost[i];
                b=i+1;
            }
        }
    }
    
    cout<<a<<" "<<b<<endl;
    
    
}