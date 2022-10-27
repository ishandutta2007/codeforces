#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
int n;
vector<int> v; LL p[16];

bool chk(int s) {
    int fg=0;
    LL sum=0;
    for(int i=0;i<v.size();i++) {
        if((s>>i)&1) {
            if (v[i] == 0 && fg == 0)
                return 0;
            fg=1;
            sum = sum*10+v[i];
        }
    }
    LL t=(LL)sqrt(sum);
    if(t*t<sum) t++;
    return t*t==sum;
}

int main(){
    p[0]=1;for(int i=1;i<11;i++)p[i]=p[i-1]*10L;
    cin >> n;

    vector<int> tmp;
    while (n) { tmp.push_back(n%10); n/=10; }
    for (int i=tmp.size()-1;i>=0;i--) v.push_back(tmp[i]);
    int sz=v.size();
    int s = 1 << (v.size());
    int ans=100;
    for (int i=1;i<s;i++) {
        if (chk(i)) {
            int c=0;
            for(int j=0;j<sz;j++) if((i>>j)&1) c++;
            c=sz-c;
            ans=min(ans,c);
        }
    }
    if(ans==100)ans=-1;
    cout<<ans<<endl;
}