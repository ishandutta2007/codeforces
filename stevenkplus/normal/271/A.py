# http://codeforces.com/problemset/problem/271/A you start this should be like a 2-liner with python?

#sry i see it now


def check(x): # let's practice writing functions though and yeah i think list == array so not list prolly
# http://anh.cs.luc.edu/python/hands-on/3.1/handsonHtml/functions.html
    return len(set(str(x)))==len(str(x)) # should work??
y = int(input()) + 1 #scott wait you don't even right? you can do like list(str(y)) or something

while check(y) is False: y+=1 #scott

print(y) #steven remember ++ doesn't exist