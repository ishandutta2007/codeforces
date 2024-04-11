from sys import *
	
MAXN=10**5+228
MOD=10**9+7

def tosumupW(board):
    d={"q":9,"r":5,"b":3,"n":3,"p":1}
    res=0
    for i in board:
        res+=d.get(i,0)
    return res

def tosumupB(board):
    d={"Q":9,"R":5,"B":3,"N":3,"P":1}
    res=0
    for i in board:
        res+=d.get(i,0)
    return res

board=""
for i in range(8):
    board+=input()
if tosumupW(board)<tosumupB(board):
    print("White")
elif tosumupW(board)==tosumupB(board):
    print("Draw")
else:
    print("Black")