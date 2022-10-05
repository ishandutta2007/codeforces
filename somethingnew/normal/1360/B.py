def main():
    n = int(input())
    lst = list(map(int,input().split()))
    lst.sort()
    ans = lst[1] - lst[0]
    for i in range(1, n):
        ans = min(ans, lst[i] - lst[i-1])
    print(ans)
for t in range(int(input())):
    main()