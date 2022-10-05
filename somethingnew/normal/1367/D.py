def main():
    st = input()
    n = int(input())
    lst = list(map(int,input().split()))
    alph = [0 for i in range(ord("z") - ord("a") + 1)]
    for i in st:
        alph[ord(i) - ord("a")] += 1
    ans = [-1 for i in range(n)]
    for i in range(len(alph)-1, -1, -1):
        if alph[i] != 0:
            k = anns(ans, lst)
            hw = 0
            for j in k:
                if ans[j] == -1:
                    hw += 1
            if hw <= alph[i]:
                for j in anns(ans, lst):
                    if ans[j] == -1:
                        ans[j] = i
    for i in ans:
        print(chr(i + ord("a")), end='')
    print()
def anns(lst, lnum):
    nm = 0
    lg = 0
    rg = 0
    lstnum = [0 for i in range(len(lst))]
    for i in range(1, len(lst)):
        if lst[i] != -1:
            nm += i
            rg += 1
    if lst[0] != -1:
        lg += 1
    lstnum[0] = nm
    for i in range(1, len(lst)):
        if lst[i] == -1:
            lstnum[i] = lstnum[i-1] + lg - rg
        else:
            lstnum[i] = lstnum[i-1] + lg - rg
            lg += 1
            rg -= 1
    ansk = []
    for i in range(len(lst)):
        if lstnum[i] == lnum[i]:
            ansk.append(i)
    return ansk
for t in range(int(input())):
    main()