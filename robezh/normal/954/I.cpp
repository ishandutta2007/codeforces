#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

#define swap(a, b) auto tmp = a; a = b, b = tmp;

struct Complex{
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0){
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

const int N = 133000, A = 6;
Complex x1[2*N], x2[2*N];
string s,t;
bool cnnted[N][A][A];
bool vis[N][A];

void dfs(int k, int v){
    vis[k][v] = true;
    for(int i = 0; i < A; i++){
        if(cnnted[k][v][i] && !vis[k][i]) dfs(k, i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> s >> t;
    int len1 = s.length(), len2 = t.length();
    int len = 1;
    while(len < 2 * len1 || len < 2 * len2) len *= 2;
    for(int i = 0; i < A; i++){
        for(int j = 0; j < A; j++){
            if(i == j) continue;
            char ci = (char)(i + 'a'), cj = (char)(j + 'a');
            for(int k = 0; k < len1; k++) x1[k] = Complex(s[k] == ci, 0);
            for(int k = len1; k < len; k++) x1[k] = Complex();
            for(int k = 0; k < len2; k++) x2[k] = Complex(t[len2-1-k] == cj, 0);
            for(int k = len2; k < len; k++) x2[k] = Complex();
            fft(x1, len, 1), fft(x2, len, 1);
            for(int k = 0; k < len; k++) x1[k] = x1[k] * x2[k];
            fft(x1, len, -1);
//            for(int k = 0; k < len; k++) cout << x1[k].x << " ";
//            cout << endl;
            for(int k = len2 - 1; k < len1; k++){
                cnnted[k][i][j] |= cnnted[k][j][i] |= (((int)(x1[k].x + 0.5)) > 0);
            }
        }
    }
    for(int k = len2 - 1; k < len1; k++){
        int res = 0;
        for(int i = 0; i < A; i++){
            if(!vis[k][i]){
                dfs(k, i), res++;
            }
        }
        cout << A - res << " ";
    }
}