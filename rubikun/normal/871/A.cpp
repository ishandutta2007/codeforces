#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        if(N%4==0){
            cout<<N/4<<"\n";
        }else if(N%4==1){
            if(N>=9){
                cout<<(N-5)/4<<"\n";
            }else{
                cout<<"-1\n";
            }
        }else if(N%4==2){
            if(N>=6){
                cout<<(N-2)/4<<"\n";
            }else{
                cout<<"-1\n";
            }
        }else{
            if(N>=15){
                cout<<(N-7)/4<<"\n";
            }else{
                cout<<"-1\n";
            }
        }
    }
}