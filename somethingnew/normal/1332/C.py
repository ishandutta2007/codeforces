for krya in range(int(input())):
    n, k = map(int, input().split())
    st = input()
    ans = 0
    stn = []
    for i in range(k):
        stn.append(st[i::k])
    newlst = []
    for i in range(k // 2):
        newlst.append(stn[i] + stn[-1-i])
    if k % 2 == 1:
        newlst.append(stn[k//2])
    for i in newlst:
        bukvi = [0] * 26
        num = 0
        for j in list(i):
            num += 1
            bukvi[ord(str(j)) - ord('a')] += 1
        ans += num - max(bukvi)
    print(ans)