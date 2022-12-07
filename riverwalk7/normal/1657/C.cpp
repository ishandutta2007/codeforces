#include <bits/stdc++.h>
#define MAXP 1000000
using namespace std;
typedef long long ll;
int T; string S;
ll p1, p2, p3, q1, q2, q3; //conducts 3 independent hashes
ll hash1, hash2, hash3; //the values of the 3 hashes so far
ll revhash1, revhash2, revhash3;
int N;
vector<int> primes;
bool factor[MAXP];
int f(char c)
{
    if(c == '(')
    {
        return 1;
    }
    if(c == ')')
    {
        return 3;
    }
}
void solve(string S)
{
    int cur = 0;
    int lastcur = 0;
    int tot_operations = 0;
    bool flag = true; int depth = 0;
    ll m1 = 1; ll m2 = 1; ll m3 = 1;
    hash1 = hash2 = hash3 = revhash1 = revhash2 = revhash3 = 0;
    while(cur != N)
    {
        hash1 *= p1; hash1 += f(S[cur]); hash1 %= q1;
        hash2 *= p2; hash2 += f(S[cur]); hash2 %= q2;
        hash3 *= p3; hash3 += f(S[cur]); hash3 %= q3;
        revhash1 += m1 * f(S[cur]); revhash1 %= q1;
        revhash2 += m2 * f(S[cur]); revhash2 %= q2;
        revhash3 += m3 * f(S[cur]); revhash3 %= q3;
        m1 = m1 * p1 % q1;
        m2 = m2 * p2 % q2;
        m3 = m3 * p3 % q3;
        if(S[cur] == '(')
        {
            ++depth;
        }
        if(S[cur] == ')')
        {
            --depth;
        }
        if(depth < 0)
        {
            flag = false;
        }
        if(flag == true && depth == 0)
        {
            lastcur = cur+1;
            tot_operations++;
            m1 = m2 = m3 = 1;
            hash1 = hash2 = hash3 = revhash1 = revhash2 = revhash3 = 0;
        }
        else if(cur != lastcur && hash1 == revhash1 && hash2 == revhash2 && hash3 == revhash3)
        {
            lastcur = cur+1;
            flag = true;
            tot_operations++;
            m1 = m2 = m3 = 1;
            depth = 0;
            hash1 = hash2 = hash3 = revhash1 = revhash2 = revhash3 = 0;
        }
        ++cur;
    }
    cout<<tot_operations<<" "<<N - lastcur<<endl;
}
int main()
{
    for(int i=2; i<MAXP; i++)
    {
        if(!factor[i])
        {
            primes.push_back(i);
            for(int j=i; j<MAXP; j += i)
            {
                factor[j] = true;
            }
        }
    }
    srand(time(NULL));
    int PS = primes.size();
    p1 = primes[rand() % PS];
    p2 = primes[rand() % PS];
    p3 = primes[rand() % PS];
    q1 = primes[rand() % PS];
    q2 = primes[rand() % PS];
    q3 = primes[rand() % PS];
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N>>S;
        solve(S);
    }
}