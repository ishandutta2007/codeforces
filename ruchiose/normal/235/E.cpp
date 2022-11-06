#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int A, B, C;
const int Sieve = 0x3FFFFFFF;

int rid[2010], r0;

struct Memoblock
{
    int V[90];
    void clear()
    {
        int i;
        fortodo(i, 1, r0) V[i] = -1;
    }
};

void code_id_in_block()
{
    int i;
    r0 = 0;
    fortodo(i, 1, C) rid[i] = 0;
    fortodo(i, 1, C)
        if (rid[C / i] == 0)
            rid[C / i] = ++r0;
}

int cob[4000002], uob[4000002], bs0;

void code_out_of_block()
{
    int i, j, F = A * B;
    fortodo(i, 1, F) cob[i] = uob[i] = 0; bs0 = 0;
    fortodo(i, 1, A)
        fortodo(j, 1, B)
            {
                uob[i * j]++;
                if (cob[i * j] == 0)
                    cob[i * j] = ++bs0;
            }
}

Memoblock* M[1200001];

int P[2000010], Div[4000010], lyr[4000010], core[4000010];
int D[4000010], prd[2010];
 
void Eusieve(int N)
{
    int i, j;
    Div[1] = lyr[1] = P[0] = 0;
    fortodo(i, 2, N) Div[i] = i;
    fortodo(i, 2, N)
        {
            if (Div[i] == i)
                {
                    lyr[i] = core[i] = 1;
                    P[++P[0]] = i;
                }
            fortodo(j, 1, P[0])
                {
                    if (i * P[j] > N) break;
                    Div[i * P[j]] = P[j];
                    if (i % P[j] == 0)
                        {
                            lyr[i * P[j]] = lyr[i] + 1;
                            core[i * P[j]] = core[i];
                            break;
                        }
                    else
                        {
                            lyr[i * P[j]] = 1;
                            core[i * P[j]] = i;                          
                        }
                }
        }
    D[1] = 1;
    fortodo(i, 2, N)
        D[i] = (lyr[i] + 1) * D[core[i]];
    prd[0] = 0;
    fortodo(i, 1, C)
        prd[i] = prd[i - 1] + D[i];
}

void initialize()
{
    int i;
    fortodo(i, 1, bs0) M[i] = NULL;
    Eusieve(max(A * B, C));
}

bool Call_memory(int a, int b, int &r)
{
    if (M[cob[a]] == NULL) return false;
    r = M[cob[a]]->V[rid[b]];
    return (r >= 0);    
}

void Set_memory(int a, int b, int r)
{
    if (M[cob[a]] == NULL)
        {
            M[cob[a]] = new Memoblock;
            M[cob[a]]->clear();
        }
    M[cob[a]]->V[rid[b]] = r;
}

int i;

int Sd(int r, int k)
{
    int ans;
    if (r == 0) return 0;
    if (Call_memory(k, r, ans)) return ans;
    if (r == 1) return D[k];
    if (k == 1) return prd[r];
    #define _p Div[k]
    #define _a lyr[k]
    #define _q core[k]
    ans = (_a + 1) * Sd(r, _q) - _a * Sd(r / _p, _q);
    ans &= Sieve;
    Set_memory(k, r, ans);
    return ans;
}

int ANS;

int main()
{
    scanf("%d%d%d", &A, &B, &C);
    code_id_in_block();
    code_out_of_block();
    initialize();
    ANS = 0;
    for (i = A * B; i; i--)
        if (cob[i])
            {
                ANS += uob[i] * Sd(C, i);
                delete M[cob[i]];
                M[cob[i]] = NULL;
            }
    ANS &= Sieve;
    printf("%d\n", ANS);
}