#include <cstdio>
#include <vector>
using namespace std;
#define pb push_back

int n, k;
bool get[910];
vector<int> chi[30];

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++){
	int tmp;
	scanf("%d", &tmp);
	chi[i].pb(tmp);
	get[tmp] = 1;
    }
    int pos = 0;
    for(int i = 1; i <= n * k; i++){
	if(!get[i]){
	    while(chi[pos].size() >= n) pos++;
	    chi[pos].pb(i);
	}
    }
    for(int i = 0; i < k; i++){
	for(int j = 0; j < n; j++){
	    printf("%d", chi[i][j]);
	    if(j == n - 1) printf("\n");
	    else printf(" ");
	}
    }
    return 0;
}