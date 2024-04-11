/* Order Michael, Jacob */
#include <cstdio> // sort by b, store largest a so far
// more includes.... (/cheat--back to you)
#include <algorithm> // oops; also I don't see why largest is enough? don't we need the number?
using namespace std; // i was sort of wrong: we should sort by a and store largest b.  read the problem, we don't need # pairs, just number contained in at least one other
int arr[999999]; // yeah I agree now, what you said works
int arr2[999999]; // we need pairs, I guess we'll write a comparator for indices
pair<int,int> dates[999999]; // I think just doing this will make our lives easier, good point
int main() { // sure
    int n; scanf("%d", &n); //is that cheating? 
    for (int i = 0; i < n; i++) scanf("%d%d", &dates[i].first, &dates[i].second);
    sort(dates, dates + n);
    int largest_b = -1;
    for(int i = 0; i < n; i++){
        } int answer = 0;
    //for(int i = 0; i < n; i++) answer += dates[i].second < (largest_b = min(largest_b, dates[i].second)) ? 1 : 0; // we could've stored it in arr[0]
    //printf("%d\n", answer[0]); CHEAT
    for(int i = 0; i < n; i++) answer += dates[i].second < (largest_b = max(largest_b, dates[i].second)) ? 1 : 0; //oh wait I fucked up; should be max
    printf("%d\n", answer);
    return 0; }