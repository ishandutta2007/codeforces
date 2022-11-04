#include <cstdio>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;
const int N = 101;
typedef pair<int, int> duo;

int t, n;
duo a[N];

vector<duo> vec;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].first);
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[j].second);
        vec.clear();
        for (int i = 1; i < n; i++)
            for (int j = n - 1; j >= i; j--){
                if(a[j] > a[j + 1]){
                    vec.push_back(duo(j, j + 1));
                    swap(a[j], a[j + 1]);
                }
            }
        bool flag = true;
        for (int i = 1; i < n; i++)
            if(!(a[i].first <= a[i + 1].first && a[i].second <= a[i + 1].second))
                flag = false;
        if(!flag)
            puts("-1");
        else{
            printf("%d\n", (int)vec.size());
            for(duo pr : vec)
                printf("%d %d\n", pr.first, pr.second);
        }
    }
    return 0;
}