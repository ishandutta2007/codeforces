#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

LL f(LL x) {
    LL k=5,ans=0;
    while(k<=x) {
        ans+=x/k; k*=5;
    } return ans;
}
int m;
vector<int> v;
int main(){
    cin>>m;
    for(int i=1;i<=500000;i++) {
        if(f(i)==m) v.push_back(i);
    }
    printf("%d\n",v.size());
    for(auto x: v) printf("%d ", x);
}