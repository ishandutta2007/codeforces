#include <iostream>
#include <string>
using namespace std;

int n;
int d[102][102];

void WarshallFroyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = 1000;
    for(int i = 0; i < n; i++) d[i][i] = 0;
    string s[102];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < n; j++) if(s[i][j] == '1') d[i][j] = 1;
    }
    WarshallFroyd();
/*    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << d[i][j];
        cout << endl;
    }*/
    int m;
    cin >> m;
    int p[1000002];
    for(int i = 0; i < m; i++){
        scanf("%d", &p[i]);
        p[i]--;
    }
    int ans = 2;
    int last = 0;
    int dis = 1;
    for(int i = 1; i < m; i++){
//        cout << last << " " << i << " " << d[p[last]][p[i]] << " " << dis << endl;
        if(d[p[last]][p[i]] != dis){
            ans++;
            last = i - 1;
            dis = 1;
            i--;
        }
        else dis++;
    }
    cout << ans << endl;
    last = 0;
    dis = 1;
    cout << p[0] + 1 << " ";
    for(int i = 1; i < m; i++){
        if(d[p[last]][p[i]] != dis){
            cout << p[i - 1] + 1 << " ";
            last = i - 1;
            i--;
            dis = 1;
        }
        else dis++;
    }
    cout << p[m - 1] + 1 << endl;
}