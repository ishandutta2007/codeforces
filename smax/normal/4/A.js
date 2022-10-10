const readline = require("readline").createInterface({
    input: process.stdin
});

readline.on("line", line => {
    let w = parseInt(line);
    if (w % 2 == 0 && w > 2)
        console.log("YES");
    else
        console.log("NO");
    readline.close();
});