#include <iostream>
#include <vector>
using namespace std;
const int N = 300000 + 10;
int n;
vector<int> vec[N];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for(int i=1;i<=2*n;i++) {
        int x; scanf("%d",&x); vec[x].push_back(i);
    }
    for(int i=1;i<=5000;i++){
        if((int)vec[i].size()%2) {
            return !printf("-1\n");
        }
    }
    for(int i=1;i<=5000;i++){
        for(int j=0;j<vec[i].size();j+=2)
            printf("%d %d\n", vec[i][j], vec[i][j+1]);
    }
}