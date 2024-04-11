def main():
    n=int(input())
    a=[(lambda s: [s[i:]+s[:i] for i in range(len(s))])(input()) for i in range(n)]
    ans=10**9
    for i in range(len(a[0])):
        c=i
        for j in range(1, n):
            for k in range(len(a[j])):
                if a[j][k]==a[0][i]:
                    c+=k
                    break
            else:
                break
        else:
            ans=min(ans,c)
    if ans==10**9:
        print(-1)
    else:
        print(ans)
main()