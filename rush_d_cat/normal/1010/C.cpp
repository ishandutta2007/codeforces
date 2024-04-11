#include <iostream>
#include <vector>
using namespace std;
const int N = 100000 + 10;

int n,k;
int a[N];
vector<int> ans;
int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    int sum = k;
    for(int i=1;i<=n;i++) {
        sum = gcd(sum, a[i]);
    }
   
    ans.push_back(0);
    for(int i=sum;i<k;i+=sum) {
        ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for(int i=0;i<ans.size();i++) 
        printf("%d ", ans[i]);
}