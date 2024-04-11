#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N=302;
int n,a[N];
vector<int> v1,v2;
bool cmp(int x,int y){
    return x>y;
}
int main() {
    scanf("%d",&n);
    int s=0,s2=0;
    for(int i=1;i<=2*n-1;i++) {
        scanf("%d",&a[i]); s+=a[i];
        s2 += abs(a[i]);
        if(a[i]<0) v1.push_back(a[i]);
        else v2.push_back(a[i]);
    }
    if(n%2==1) {
        printf("%d\n", s2); return 0;
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1.size()%2==0) for(auto p: v1) s -= 2*p;
    else {
        for(int i=0;i<(int)v1.size()-1;i++) s -= 2*v1[i];
        if(v2.size() && v2[0] < -v1[(int)v1.size() - 1]) {
            s += 2 * (-v1[(int)v1.size()-1] - v2[0]);
        }
    }
    printf("%d\n", s);
}