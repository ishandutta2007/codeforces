n = int(raw_input())
child = [set({}) for i in range(0, n + 1)]
query = [list({}) for i in range(0, n + 1)]
ans = [dict(set({})) for i in range(0, n + 1)]
ss = [0 for i in range(0, n + 1)]
fa = [0 for i in range(0, n + 1)]
hash_string = dict()
nowstrings = 0
for i in range(1, n + 1):
    s = raw_input().split()
    child[int(s[1])] |= {i}
    fa[i] = int(s[1])
    if s[0] not in hash_string:
        nowstrings += 1
        hash_string[s[0]] = nowstrings
    ss[i] = hash_string[s[0]]
fa[0] = -1
Child = [list(child[i]) for i in range(0, n+1)]
lenChild = [len(Child[i]) for i in range(0, n+1)]
nowChild = [0 for i in range(0, n+1)]
m = int(raw_input())
answer = [0 for i in range(0, m)]
for i in range(0, m):
    s = raw_input().split()
    query[int(s[0])] += {int(s[1])}
    query[int(s[0])] += {i}
def dfs(x, dep):
    while x != -1:
        if nowChild[x] == lenChild[x]:
            if x != 0:
                ans[x][dep] = {ss[x]}
                for nowlistindex in range(0, len(query[x]), 2):
                    i = query[x][nowlistindex]
                    j = query[x][nowlistindex+1]
                    if dep + i not in ans[x]:
                        answer[j] = 0
                    else:
                        answer[j] = len(ans[x][dep + i])
                """count ans"""
                if len(ans[x]) < len(ans[fa[x]]):
                    for j in ans[x]:
                        if j not in ans[fa[x]]:
                            ans[fa[x]][j] = ans[x][j]
                        elif len(ans[x][j]) < len(ans[fa[x]][j]):
                            ans[fa[x]][j] |= ans[x][j]
                            ans[x][j].clear()
                        else:
                            ans[x][j] |= ans[fa[x]][j]
                            ans[fa[x]][j].clear()
                            ans[fa[x]][j] = ans[x][j]
                    ans[x].clear()
                else:
                    for j in ans[fa[x]]:
                        if j not in ans[x]:
                            ans[x][j] = ans[fa[x]][j]
                        elif len(ans[x][j]) > len(ans[fa[x]][j]):
                            ans[x][j] |= ans[fa[x]][j]
                            ans[fa[x]][j].clear()
                        else:
                            ans[fa[x]][j] |= ans[x][j]
                            ans[x][j].clear()
                            ans[x][j] = ans[fa[x]][j]
                    ans[fa[x]].clear()
                    ans[fa[x]] = ans[x]
            x = fa[x]
            nowChild[x] += 1
            dep -= 1
        else:
            x = Child[x][nowChild[x]]
            dep += 1
dfs(0, 0)
for i in range(0, m):
    print(answer[i])