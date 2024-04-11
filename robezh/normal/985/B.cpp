#include <bits/stdc++.h>
using namespace std;

int n,m;
string num[2005];
int sum[2005];
vector<int> uni[2005];

int main(){
    scanf("%d%d", &n, &m);
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin, num[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum[j] += (num[i][j] - '0');
        }
    }
    for(int j = 0; j < m; j++){
        if(sum[j] == 1){
            for(int i = 0; i < n; i++){
                if(num[i][j] == '1') uni[i].push_back(j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(uni[i].size() == 0) return !printf("YES");
    }
    printf("NO");

}