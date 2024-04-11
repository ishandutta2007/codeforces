N = int(input())
for i in range(N):
    input()
    L=list(map(int,input().split()))
    L.sort(reverse=True)
    print(*L)