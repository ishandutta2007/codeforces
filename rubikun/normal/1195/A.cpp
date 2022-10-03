#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    vector<int> cnt(K);
    for(int i=0;i<N;i++){
        int a;cin>>a;
        a--;
        cnt[a]++;
    }
    
    if(N%2==0){
        int sum=0;
        for(int i=0;i<K;i++){
            sum+=(cnt[i])/2;
            cnt[i]=cnt[i]%2;
        }
        sort(all(cnt));
        if(sum==N/2) cout<<sum*2<<endl;
        else{
            int m=N/2-sum;
            sum*=2;
            for(int i=0;i<m;i++){
                sum+=cnt[K-1-i];
            }
            cout<<sum<<endl;
        }
    }else{
        int sum=0;
        for(int i=0;i<K;i++){
            sum+=(cnt[i])/2;
            cnt[i]=cnt[i]%2;
        }
        sort(all(cnt));
        if(sum==N/2) cout<<N<<endl;
        else{
            int m=N/2+1-sum;
            sum*=2;
            for(int i=0;i<m;i++){
                sum+=cnt[K-1-i];
            }
            cout<<sum<<endl;
        }
    }
}