#include <cstdlib>
#include <iostream>
using namespace std;

const int MOD = 1000000007;
const int ST = 1<<7;

void add(int &a, int b){ a = (a+b) % MOD; }
int mul(int a, int b){ return (a * 1LL * b) % MOD; }

int M = 0;

struct mat{
    int N, **dat;
    mat(int _N, int diag = 0){
        N = _N;
        dat = (int **) malloc(sizeof(int*) * N);
        for(int i=0; i<N; i++){
            dat[i] = (int *) calloc(N, sizeof(int));
            dat[i][i] = diag;
        }
    }
    ~mat(){
        for(int i=0; i<N; i++) free(dat[i]);
        free(dat);
    }

    mat *operator *(const mat &b){
        mat *r = new mat(N);
        for(int i=M; i<N; i++)
            for(int j=M; j<N; j++)
                for(int k=M; k<N; k++)
                    add(r->dat[i][j], mul(dat[i][k], b.dat[k][j]));
        return r;
    }

    mat *pow(long long E){
        if(E == 0) return new mat(N, 1);
        mat *b = (*this) * (*this);
        mat *p = b->pow(E/2);
        delete b;
        if(E % 2){ mat *q = *p * *this; delete p; return q; }
        return p;        
    }
};

mat *trans(int r){
    mat *a = new mat(ST);
    for(int j=M; j<ST; j++)
        for(int i=M; i<ST; i++)
            for(int hm=0; hm<(1<<(r-1)); hm++){
                bool good = true;
                for(int b=0; b<r; b++){
                    int sides = 0;
                    if(b==0 || ((hm>>(b-1))&1)) sides++;
                    if(b+1==r || ((hm>>b)&1)) sides++;
                    if((j>>b)&1) sides++;
                    if((i>>b)&1) sides++;
                    good &= sides < 4;
                }
                a->dat[j][i] += good;
            }
    return a;
}

int main(){
    mat *a = new mat(ST, 1);

    for(int i=1; i<=7; i++){
        M = ST-(1<<i);

        int P; cin >> P;
        mat *t = trans(i);
        mat *e = t->pow(P);
        mat *p = *a * *e;
        delete a, delete t, delete e;
        a = p;
    }

    cout << a->dat[ST-1][ST-1] << endl;
}