#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#define MAXN 100100
using namespace std;
int T; //number of test cases
int N; //the number of T-shirts
map<int, int> even_position_occurrences; //number of that value initially in even position
map<int, int> odd_position_occurrences; //number of that value initially in odd position
int a[MAXN]; //the original array
bool solve()
{
    /* Returns True if the number of even positioned occurrences of each value is the same in the original array and the sorted array
    Else False

    Note that the direction of a friend is right if the distance between the friend and it's original position is even,
    and left if the distance between the friend and it's original position is odd
    */
    cin>>N;
    even_position_occurrences.clear();
    odd_position_occurrences.clear();
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        if(i % 2 == 0)
        {
            even_position_occurrences[a[i]]++;
        }
        if(i % 2 == 1)
        {
            odd_position_occurrences[a[i]]++;
        }
    }
    sort(a, a+N);
    for(int i=0; i<N; i++)
    {
        if(i % 2 == 0)
        {
            even_position_occurrences[a[i]]--;
            if(even_position_occurrences[a[i]] < 0) //we have a mismatch since a[i] occurs more often in even positions than what we want
            {
                return false;
            }
        }
        if(i % 2 == 1)
        {
            odd_position_occurrences[a[i]]--;
            if(odd_position_occurrences[a[i]] < 0) //we have a similar mismatch here
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cout<<(solve() ? "YES": "NO")<<endl;
    }
}