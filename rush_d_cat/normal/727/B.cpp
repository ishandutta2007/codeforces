#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000 + 10;
const int MAXM = 200000 + 10;
char s[MAXN];
bool isDot[MAXN];
vector<char> vec;
bool isNum(char c)
{
    if(c >= '0' && c <= '9') return 1;
    return 0;
}
int main()
{
    int i;
    cin >> s;
    int len = strlen(s);
    double sum = 0;
    for(i = 0; i < len; i++)
    {
        if(s[i] == '.')
        {
            if(isNum(s[i+1]) && isNum(s[i+2]) && (!isNum(s[i+3]) && s[i+3] != '.'))
            {
                isDot[i] = 1;
            }
        }
    }
    for(i = 0; i < len; i++)
    {
        double tmp = 0;
        while((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
        {
            if(isDot[i])
            {
                tmp += 0.1 * (s[++i] - '0');
                tmp += 0.01 * (s[++i] - '0');
            } else if(s[i] >= '0' && s[i] <= '9'){
                tmp = tmp * 10 + s[i] - '0';
            }
            i++;
        }
        sum += tmp;
    }
    sum += 1e-6;
    int sum_ = (int)sum;
    int cnt = 0;
    while(sum_)
    {
        int t = sum_%10;
        sum_ /= 10;
        vec.push_back((char)(t+'0'));
        cnt++;
        if(cnt%3==0 && sum_) vec.push_back('.');
    }
    if(vec.size() == 0)
        cout<<0;
    else{
        for(i = vec.size()-1;i>=0;i--)
        {
            cout<<vec[i];
        }
    }
    double x =  sum - (int)sum;
    int y = (100 * x);
    if(sum-(int)sum>1e-4)
    {
        if(100*x>=10)
            cout <<"."<< (int)(100*x+1e-4);
        else
            cout << ".0" << (int)(100*x+1e-4) << endl;
    }
}