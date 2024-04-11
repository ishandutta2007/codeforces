#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 100000+10;
int n,a[N],b[N];
vector<int> vec[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        vec[n-a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if((int)vec[i].size() % i) return !printf("Impossible\n");
    }
    printf("Possible\n");
    int tot=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<vec[i].size();j++){
            if(j%i == 0) ++ tot;
            b[vec[i][j]] = tot;
        }
    }
    for(int i=1;i<=n;i++) printf("%d ", b[i]);
}