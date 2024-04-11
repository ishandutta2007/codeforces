from collections import defaultdict

def solve():
    n = int(input())
    arr = [*map(int, input().split())]
    byelem = defaultdict(lambda: [])
    for i, v in enumerate(arr): 
        byelem[v].append(i)
    ans = 0
    for lst in byelem.values():
        lessSum = 0
        for v in lst:
            ans += lessSum * (n - v)
            lessSum += (v + 1)
    return ans

t = int(input())
for tc in range(t):
    print(solve())