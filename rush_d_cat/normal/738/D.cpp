#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int NICO = 200002;
int n, a, b, k;
char mp[NICO];
vector<int> vec;
int main()
{
    cin >> n >> a >> b >> k;
    scanf("%s", mp+1);
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        if(mp[i] == '0')
        {
            sum ++;
            if(sum % b == 0)
            {
                vec.push_back(i);
            }
        } else {
            sum = 0;
        }
    }
    int cnt = 0;
    int res = vec.size() - a + 1;
    printf("%d\n", res);
    for(int i=0;i<vec.size();i++)
    {
        printf("%d", vec[i]);
        cnt++;
        if(cnt == res)
        {
            printf("\n");
            break;
        } else {
            printf(" ");
        }
    }
}