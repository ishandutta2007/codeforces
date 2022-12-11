#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;


int main() {
    char a[60][60],b[60][60];
    int na,ma,nb,mb;
    cin >> na >> ma;
    for (int i = 0;i < na; i++)
        scanf("%s",a[i]);
    cin >> nb >> mb;
    for (int i = 0;i < nb; i++)
        scanf("%s",b[i]);
    int ansx,ans = 0,ansy;
    for (int x = -50; x <= 50; x ++)
        for (int y = -50; y <= 50; y++){
            int tmp = 0;
            for (int i = 0; i < na; i ++)
                for (int j = 0; j < ma; ++j)
                    if (i + x >= 0 && i + x < nb && j + y >= 0 && j + y < mb){
                        tmp += (a[i][j]-'0')*(b[i+x][j+y]-'0');
                }
            if (ans < tmp){
                ans = tmp;
                ansx = x;
                ansy = y;
            }
        }
    cout << ansx << ' ' << ansy << endl;
    return 0;
}