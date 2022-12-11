import sys

html = ''.join([s.rstrip() for s in sys.stdin.readlines()])

html = html.split('<')
curStack = []
ans = []

for token in html:
    if token == "table>":
        curStack.append(0)
    elif token == "/table>":
        ans.append(curStack.pop())
    elif token == "/td>":
        curStack[-1] += 1

print(*sorted(ans))