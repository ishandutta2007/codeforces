let fs = require("fs");
let allInput = fs.readFileSync(0).toString(); // STDIN_FILENO = 0
let allLines=allInput.split('\n');
let line=0;
const T=parseInt(allLines[line++]);
function count(a, b) {
    let c=0;
    while (a*2<b) {
        a*=2;
        c++;
    }
    while (b*2<a) {
        b*=2;
        c++;
    }
    return c;
}

for (let tt=0; tt<T; tt++) {
    const n=parseInt(allLines[line++]);
    const a=allLines[line++].split(" ").map(Number);
    let add=0;
    for (let ind=0; ind+1<n; ind++) {
        add+=count(a[ind], a[ind+1]);
    }
    console.log(add);
}