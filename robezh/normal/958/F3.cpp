#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
typedef long long ll;

#define swap(a, b) auto tmp = a; a = b, b = tmp;

struct Complex{
    long double x, y;
    Complex(long double _x = 0.0, long double _y = 0.0){
        x = _x, y = _y;
    }
    Complex operator - (const Complex &b) const{
        return Complex(x - b.x, y - b.y);
    }
    Complex operator + (const Complex &b) const{
        return Complex(x + b.x, y + b.y);
    }
    Complex operator * (const Complex &b) const{
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

void change(Complex y[], int len){
    int i, j, k;
    for(i = 1, j = len/2; i < len - 1; i++){
        if(i < j){Complex tmp = y[i]; y[i] = y[j], y[j] = tmp;}
        k = len / 2;
        while(j >= k){
            j = j - k;
            k = k / 2;
        }
        if(j < k) j += k;
    }
}

void fft(Complex y[], int len, int on){
    change(y, len);
    for(int h = 2; h <= len; h <<= 1){
        Complex wn(cos(-on*2*PI/h), sin(-on*2*PI/h));
        for(int j = 0; j < len; j += h){
            Complex w(1,0);
            for(int k = j; k < j + h/2; k++){
                Complex u = y[k];
                Complex t = w * y[k + h/2];
                y[k] = u + t;
                y[k + h/2] = u - t;
                w = w * wn;
            }
        }
    }
    if(on == -1){
        for(int i = 0; i < len; i++){
            y[i].x /= len;
        }
    }
}

const int N = 263000, mod = 1009;
typedef pair<int, int> P;

Complex x1[2*N], x2[2*N];
int n,m,k;
int cnt[N];
priority_queue<P, vector<P>, greater<P> > pque;
vector<int> cof[N];

void conv(int k1, int k2){
    int len1 = cof[k1].size(), len2 = cof[k2].size(), len = 1;
    while(len < 2 * len1 || len < 2 * len2) len *= 2;

    for(int i = 0; i < len1; i++) x1[i] = Complex(cof[k1][i], 0);
    for(int i = 0; i < len2; i++) x2[i] = Complex(cof[k2][i], 0);
    for(int i = len1; i < len; i++) x1[i] = Complex();
    for(int i = len2; i < len; i++) x2[i] = Complex();
    fft(x1, len, 1), fft(x2, len, 1);
    for(int i = 0; i < len; i++) x1[i] = x1[i] * x2[i];
    fft(x1, len, -1);
    cof[k1].clear(), cof[k2].clear();
    for(int i = 0; i < len1 + len2 - 1; i++) cof[k1].push_back((ll)(x1[i].x + 0.5) % mod);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    for(int i = 1; i <= m; i++){
        if(cnt[i] > 0){
            for(int j = 0; j <= cnt[i]; j++) cof[i].push_back(1);
            pque.push({cof[i].size(), i});
        }
    }
    while(pque.size() > 1){
        int fir = pque.top().second; pque.pop();
        int sec = pque.top().second; pque.pop();
        conv(fir, sec);
        pque.push({cof[fir].size(), fir});
    }
    int i = pque.top().second;
    cout << cof[i][k] << endl;

}