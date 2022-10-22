#include <iostream>
using namespace std;

char c[2003][2003];
int r[2003], l[2003], u[2003], d[2003];
int rsum[2003][2003];
int dsum[2003][2003];

int main()
{
    int n, k;
    cin >> n >> k;
    fill(r, r + n, -1);
    fill(d, d + n, -1);
    fill(l, l + n, n);
    fill(u, u + n, n);
    int ans = 0;
    int g = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        cin >> c[i][j];
        if(c[i][j] == 'B'){
            r[i] = max(r[i], j);
            l[i] = min(l[i], j);
            u[j] = min(u[j], i);
            d[j] = max(d[j], i);
        }
    }
    for(int i = 0; i < n; i++) if(r[i] < l[i]) g++;
    for(int j = 0; j < n; j++) if(d[j] < u[j]) g++;
    for(int j = 0; j <= n - k; j++){
        for(int i = 0; i < k; i++){
            if(l[i] >= j && r[i] < j + k && r[i] >= l[i]) rsum[0][j]++;
        }
        for(int i = k; i < n; i++){
            rsum[i - k + 1][j] = rsum[i - k][j];
            if(l[i - k] >= j && r[i - k] < j + k && r[i - k] >= l[i - k]) rsum[i - k + 1][j]--;
            if(l[i] >= j && r[i] < j + k && r[i] >= l[i]) rsum[i - k + 1][j]++;
        }
    }
    for(int i = 0; i <= n - k; i++){
        for(int j = 0; j < k; j++){
            if(u[j] >= i && d[j] < i + k && d[j] >= u[j]) dsum[i][0]++;
        }
        for(int j = k; j < n; j++){
            dsum[i][j - k + 1] = dsum[i][j - k];
            if(u[j - k] >= i && d[j - k] < i + k && d[j - k] >= u[j - k]) dsum[i][j - k + 1]--;
            if(u[j] >= i && d[j] < i + k && d[j] >= u[j]) dsum[i][j - k + 1]++;
        }
    }
    for(int i = 0; i <= n - k; i++) for(int j = 0; j <= n - k; j++) ans = max(ans, dsum[i][j] + rsum[i][j] + g);
    cout << ans << endl;
}