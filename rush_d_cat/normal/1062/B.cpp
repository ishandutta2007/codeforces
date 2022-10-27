#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
void F(int x) {
    int ans=1,mx=0;
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) {
            int c=0;
            while(x%i==0) {
                x/=i; c++;
            }
            ans *= i; mx=max(mx,c);
            v.push_back(c);
        }
    }
    if(x>1) {
        ans*=x; mx=max(mx,1);
        v.push_back(1);
    }
    int val=1,res=0; while(val<mx) val*=2,res++;
    bool ok=1;
    for(auto x:v) if(x!=val) ok=0;
    if(ok==0) res++;
    printf("%d %d\n", ans,res);
}

int main() {
    cin >> n; F(n);
}