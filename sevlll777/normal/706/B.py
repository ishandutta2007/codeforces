from bisect import bisect_right
n = int(input())
X = list(map(int, input().split()))
X.sort()
for _ in range(int(input())):
    print(bisect_right(X, int(input())))