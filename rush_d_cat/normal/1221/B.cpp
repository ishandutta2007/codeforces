#include <iostream>
#include <queue>
#include <set>
using namespace std;
int n,q;

int main() {
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c", (i+j)%2==0 ? 'B' : 'W');
        }
        printf("\n");
    }
}