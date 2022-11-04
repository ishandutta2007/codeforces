#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 2;

int t, n, a[N];
int premax[N], spremax[N], premin[N], spremin[N], sufmax[N], ssufmax[N], sufmin[N], ssufmin[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        premin[0] = 1e9;
        spremin[0] = 1e9;
        for (int i = 1; i <= n; i++){
            if(a[i] > premax[i - 1]){
                spremax[i] = premax[i - 1];
                premax[i] = a[i];
            }
            else if(a[i] > spremax[i - 1]){
                premax[i] = premax[i - 1];
                spremax[i] = a[i];
            }
            else{
                premax[i] = premax[i - 1];
                spremax[i] = spremax[i - 1];
            }
            if(a[i] < premin[i - 1]){
                spremin[i] = premin[i - 1];
                premin[i] = a[i];
            }
            else if(a[i] < spremin[i - 1]){
                premin[i] = premin[i - 1];
                spremin[i] = a[i];
            }
            else{
                premin[i] = premin[i - 1];
                spremin[i] = spremin[i - 1];
            }
        }
        sufmax[n + 1] = 0;
        ssufmax[n + 1] = 0;
        sufmin[n + 1] = 1e9;
        ssufmin[n + 1] = 1e9;
        for (int i = n; i >= 1; i--){
            if(a[i] > sufmax[i + 1]){
                ssufmax[i] = sufmax[i + 1];
                sufmax[i] = a[i];
            }
            else if(a[i] > ssufmax[i + 1]){
                sufmax[i] = sufmax[i + 1];
                ssufmax[i] = a[i];
            }
            else{
                sufmax[i] = sufmax[i + 1];
                ssufmax[i] = ssufmax[i + 1];
            }
            if(a[i] < sufmin[i + 1]){
                ssufmin[i] = sufmin[i + 1];
                sufmin[i] = a[i];
            }
            else if(a[i] < ssufmin[i + 1]){
                sufmin[i] = sufmin[i + 1];
                ssufmin[i] = a[i];
            }
            else{
                sufmin[i] = sufmin[i + 1];
                ssufmin[i] = ssufmin[i + 1];
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++){
            ans = max(ans, premax[i] + spremax[i] - sufmin[i + 1] - ssufmin[i + 1]);
            ans = max(ans, sufmax[i + 1] + ssufmax[i + 1] - premin[i] - spremin[i]);
            ans = max(ans, premax[i] + sufmax[i + 1] - premin[i] - sufmin[i + 1]);
        }
        printf("%d\n", ans);
    }
	return 0;
}