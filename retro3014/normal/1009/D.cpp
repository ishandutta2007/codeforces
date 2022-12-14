#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int x, int y){
    return (x==0)?y:gcd(y%x, x);
}

struct S{
    int x, y;
};
int N, M;
vector<S> v;

int main(){
    cin>>N>>M;
    if(M<N-1){
        cout<<"Impossible";
        return 0;
    }
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            if(gcd(i, j)==1){
                v.push_back({i, j});
                if(v.size()==M){
                    break;
                }
            }
        }
        if(v.size()==M){
            break;
        }
    }
    if(v.size()==M){
        cout<<"Possible"<<endl;
        for(int i=0; i<v.size(); i++){
            printf("%d %d\n", v[i].x, v[i].y);
        }
    }
    else{
        cout<<"Impossible";
    }
    return 0;
}