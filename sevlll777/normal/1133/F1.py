def digraph_from_input():
    digraph = dict()
    n, m = map(int, input().split())
    for t in range(m):
        z1, z2 = map(int, input().split())
        if z1 not in digraph:
            digraph[z1] = set([z2])
        else:
            digraph[z1].add(z2)
        if z2 not in digraph:
            digraph[z2] = set([z1])
        else:
            digraph[z2].add(z1)
    return digraph


def BFC(digraph, v):
    s2 = set()
    s1 = set()
    oboid = set()
    ans = dict()
    havepa = set()
    havepa.add(v)
    s1.add(v)
    while s1 != set():
        for element in s1:
            last_element = element
            if element not in oboid:
                oboid.add(element)
                for key in digraph[element]:
                    if key not in havepa:
                        s2.add(key)
                        havepa.add(key)
                        ans[key] = last_element
        s1 = s2
        s2 = set()
    return ans


digraph = digraph_from_input()
v = 1
for i in digraph:
    if len(digraph[i]) > len(digraph[v]):
        v = i
q = BFC(digraph, v)
for i in q:
    print(i, q[i])