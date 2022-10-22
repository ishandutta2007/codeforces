#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int ans;
int x, y;

int calc(int a){
    int c = 0;
    while(a){
        for(int j = 0; j <= 30; j++){
            if((1 << j) >= a){
                a = (1 << j) - a;
                c++;
                break;
            }
        }
    }
    return c;
}

int calc2(int a){
    int c = 0;
    while(a){
        for(int j = 0; j <= 30; j++){
            if((1 << j) - 1 >= a){
                a = (1 << j) - 1 - a;
                c++;
                break;
            }
        }
    }
    return c;
}

void rec(vector<int> v, int *a){
    int d[4];
    for(int i = 0; i < 4; i++) d[i] = -10000;
    int l[4];
    vector<int> w0, w1;
    for(int i : v){
        int c = calc2(a[i]);
        int x = a[i] & 3;
        if(c > d[x]){
            d[x] = c;
            l[x] = i;
        }
        if(x == 0 || x == 3) w0.push_back(i);
        else w1.push_back(i);
    }
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            if(i + j != 3 && d[i] + d[j] > ans){
                ans = d[i] + d[j];
                x = l[i];
                y = l[j];
            }
        }
    }
    for(int i : v) a[i] >>= 1;
    if((int)w0.size() >= 2) rec(w0, a);
    if((int)w1.size() >= 2) rec(w1, a);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v[32];
    int a[200005];
    int d[32];
    for(int i = 0; i <= 30; i++) d[i] = -10000;
    int l[32]{0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) d[30] = 0;
        int c = calc(a[i]);
        for(int j = 0; j < 30; j++){
            if((a[i] >> j) & 1){
                v[j].push_back(i);
                if(c > d[j]){
                    d[j] = c;
                    l[j] = i;
                }
                break;
            }
        }
    }
    for(int i = 0; i <= 30; i++){
        for(int j = i + 1; j <= 30; j++){
            if(d[i] + d[j] > ans){
                ans = d[i] + d[j];
                x = l[i];
                y = l[j];
            }
        }
    }
    for(int k = 0; k < 30; k++){
        for(int i : v[k]) a[i] >>= k + 1;
        rec(v[k], a);
    }
    cout << x + 1 << " " << y + 1 << " " << ans << endl;
}