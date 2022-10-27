#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 250000+10;
const double PI = acos(-1);
struct Complex {
    double x, y;
    Complex(double x=0.0, double y=0.0) : x(x), y(y) {}
    Complex operator + (const Complex &b) const {
        return Complex(x+b.x, y+b.y);
    }
    Complex operator - (const Complex &b) const {
        return Complex(x-b.x, y-b.y);
    }
    Complex operator * (const Complex &b) const{
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
} x1[N<<2], x2[N<<2];
void change(Complex y[], int len) {
    for(int i=1,j=len/2;i<len-1;i++){
        if(i<j) swap(y[i], y[j]);
        int k=len/2;
        while (j>=k) {
            j-=k; k/=2;
        }
        if(j<k) j+=k;
    }
}
void fft(Complex y[], int len, int on){
    change(y, len);
    for(int h=2;h<=len;h<<=1) {
        Complex wn(cos(-on*2*PI/h), sin(-on*2*PI/h));
        for(int j=0;j<len;j+=h){
            Complex w(1,0);
            for(int k=j;k<j+h/2;k++) {
                Complex u=y[k];
                Complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if (on==-1)
        for(int i=0;i<len;i++) y[i].x /= len;
}
void mul(int *p, int& dp, int* q, int& dq) {
    int len=1;
    while(len<=dp+dq) len<<=1;
    for(int i=0;i<dp;i++) 
        x1[i]=Complex(p[i],0);
    for(int i=dp;i<len;i++)
        x1[i]=Complex(0,0);
    for(int i=0;i<dq;i++)
        x2[i]=Complex(q[i],0);
    for(int i=dq;i<len;i++)
        x2[i]=Complex(0,0);
    fft(x1,len,1);
    fft(x2,len,1);
    for(int i=0;i<len;i++)
        x1[i]=x1[i]*x2[i];
    fft(x1,len,-1);
    for(int i=0;i<dp+dq;i++) {
        p[i]=(int)(x1[i].x+0.5);
        if(p[i]) p[i]=1;
    }
    dp+=dq;
}

char s1[N], s2[N]; 
int len1,len2;
int a[N], b[N];
int s=2,bit=1;

int ok[N][6][6];

void process(int x, int y) {
    for(int i=0;i<len1;i++){
        if(s1[i]==(char)('a'+x)){
            a[i]=1;
        }else{
            a[i]=0;
        }
    }
    for(int i=0;i<len2;i++){
        if(s2[i]==(char)('a'+y)){
            b[i]=1;
        }else{
            b[i]=0;
        }
    }
    len1=strlen(s1); len2=strlen(s2);
    //printf("%c %c\n", 'a'+x, 'a'+y);
    //for(int i=0;i<len1;i++) printf("%d ", a[i]); printf("\n");
    //for(int i=0;i<len2;i++) printf("%d ", b[i]); printf("\n");
    mul(a,len1,b,len2);
    //for(int i=0;i<len1;i++) printf("%d ", a[i]); printf("\n\n");

    for(int i=len2-1;i<len1;i++){
        if(a[i])
            ok[i][x][y]=1;
    }
}

int par[7];
int find(int x) {
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
int get_ans(int x) {
    // [x-le2+1, x]
    for (int i=0;i<6;i++) par[i]=i;
    for (int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(ok[x][i][j])
                par[find(i)]=find(j);
        }
    }
    int cnt=0;
    for(int i=0;i<6;i++)
        if(par[i]!=i) cnt++;
    return cnt;

}

int main() {
    scanf("%s %s", s1, s2);
    len1=strlen(s1),len2=strlen(s2);
    int tot=len1+len2;
    for(int i=0;i<len2;i++) if(i<len2-i-1) swap(s2[i],s2[len2-i-1]);


    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            process(i, j);
    len1=strlen(s1); len2=strlen(s2);    
    for(int i=len2-1;i<len1;i++)
        printf("%d ", get_ans(i));
    
    printf("\n");
}