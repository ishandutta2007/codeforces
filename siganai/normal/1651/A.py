import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n = int(input())
    print(2 ** n - 1)